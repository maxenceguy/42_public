/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:43:09 by magi              #+#    #+#             */
/*   Updated: 2024/07/30 15:08:11 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int		g_signal;

char	*token_to_str(t_node *token)
{
	if (token->type == NONE)
		return ("NONE");
	else if (token->type == QUOTE)
		return ("QUOTE");
	else if (token->type == DOUBLE_QUOTE)
		return ("DOUBLE_QUOTE");
	else if (token->type == REDIRECT_IN)
		return ("REDIRECT_IN");
	else if (token->type == REDIRECT_OUT)
		return ("REDIRECT_OUT");
	else if (token->type == APPEND)
		return ("APPEND");
	else if (token->type == HEREDOC)
		return ("HEREDOC");
	else if (token->type == PIPE)
		return ("PIPE");
	else if (token->type == SPACE)
		return ("SPACE");
	else if (token->type == TAB)
		return ("TAB");
	else if (token->type == EXPANDED_TEXT)
		return (token->str);
	else if (token->str)
		return (token->str);
	return (NULL);
}

void	handler(int signo)
{
	if (signo == SIGINT)
	{
		g_signal = 130;
		ft_printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

t_gen	*init_gen(char **env)
{
	t_gen	*gen;

	gen = (t_gen *)malloc(sizeof(t_gen));
	if (!gen)
	{
		perror("Failed to allocate memory for gen");
		exit(EXIT_FAILURE);
	}
	gen->canceled_hrdoc = false;
	gen->env = NULL;
	gen->node = NULL;
	gen->command = NULL;
	gen->error_code = 0;
	get_env(gen, env);
	return (gen);
}

void	process_input(t_gen *gen, char *str)
{
	int	ret;

	ret = lexer_parser(gen, str);
	if (ret != 1)
	{
		if (str[0] != '\0')
		{
			free(str);
			if (gen->command && gen->command->args[0] == NULL)
				printf("Empty args.\n");
			else if (gen->command)
				execute_commands(gen);
		}
		else if (str)
			free(str);
		free_cmd(gen);
	}
	else if (ret == -1)
		printf("EXIT_FAILURE LEXER_PARSER\n");
	g_signal = 0;
}

int	main(int argc, char **argv, char **env)
{
	char	*str;
	t_gen	*gen;

	(void)argv;
	if (argc > 1)
		return (EXIT_SUCCESS);
	gen = init_gen(env);
	signal(SIGINT, &handler);
	signal(SIGQUIT, SIG_IGN);
	g_signal = 0;
	while (1)
	{
		str = readline("minishell: ");
		if (!str)
		{
			printf("exit\n");
			ft_exit(gen);
		}
		add_history(str);
		process_input(gen, str);
	}
}

// ERROR : empty herdoc leave and didn't suppr
// Maybe 2 Globals variables
// Delete comment in heredoc_exec.c
