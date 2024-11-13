/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:10:39 by mguy              #+#    #+#             */
/*   Updated: 2024/08/01 00:18:17 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	init_echo(t_echo *echo, char **cmd)
{
	echo->n_flag = 0;
	echo->start_index = 1;
	echo->str = NULL;
	echo->tmp = NULL;
	if (cmd[0] == NULL)
	{
		echo->str = ft_strjoin(echo->str, "\n");
		if (echo->str == NULL)
			return (-1);
		return (printf("%s", echo->str), 0);
	}
	if (check_n(cmd, &echo->start_index, &echo->n_flag) == -1)
		return (-1);
	return (0);
}

static char	*join_and_free(char *s1, char *s2)
{
	char	*joined;

	joined = ft_strjoin(s1, s2);
	free(s1);
	return (joined);
}

static int	handle_echo_loop(t_echo *echo, char **cmd)
{
	echo->i = echo->start_index;
	while (cmd[echo->i] != NULL)
	{
		echo->tmp = join_and_free(echo->str, cmd[echo->i]);
		if (echo->tmp == NULL)
			return (free(echo->str), -1);
		if (cmd[echo->i + 1] != NULL)
			echo->str = join_and_free(echo->tmp, " ");
		else
		{
			echo->str = malloc(sizeof(char) * (ft_strlen(echo->tmp) + 1));
			if (echo->str != NULL)
				ft_strcpy(echo->str, echo->tmp);
			free(echo->tmp);
		}
		if (echo->str == NULL)
			return (-1);
		echo->i++;
	}
	return (0);
}

int	ft_echo(char **cmd, t_gen *gen)
{
	t_echo	echo;

	if (init_echo(&echo, cmd) == -1)
		return (gen->error_code = 1, -1);
	echo.str = malloc(sizeof(char) * 1);
	if (echo.str == NULL)
		return (gen->error_code = 1, -1);
	echo.str[0] = '\0';
	if (handle_echo_loop(&echo, cmd) == -1)
		return (gen->error_code = 1, -1);
	echo.final = join_and_free(echo.str, "\n");
	if (echo.final == NULL)
		printf("\n");
	else
	{
		if (echo.n_flag)
			echo.final[ft_strlen(echo.final) - 1] = '\0';
		printf("%s", echo.final);
	}
	free(echo.final);
	gen->error_code = 0;
	return (0);
}
