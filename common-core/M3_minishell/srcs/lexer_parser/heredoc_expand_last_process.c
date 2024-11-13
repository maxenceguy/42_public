/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expand_last_process.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:37:07 by rolamber          #+#    #+#             */
/*   Updated: 2024/07/23 19:14:17 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*get_final_ret(char *start, char *expanded, char *restofl)
{
	char	*ret;

	ret = ft_strjoin(start, expanded);
	free(start);
	free(expanded);
	if (!ret)
		return (NULL);
	if (restofl)
	{
		start = ret;
		ret = ft_strjoin(start, restofl);
		free(start);
		if (!ret)
			return (NULL);
	}
	return (ret);
}

char	*heredoc_expand_last_process(char *line, int i, t_gen *gen)
{
	char	*ret;
	char	*start;
	char	*expanded;
	char	*rest_of_the_line;

	expanded = ft_itoa(gen->error_code);
	if (!expanded)
		return (NULL);
	start = ft_substr(line, 0, i);
	if (!start)
		return (NULL);
	if (line[i + 2])
		rest_of_the_line = ft_strdup(&line[i + 2]);
	else
		rest_of_the_line = NULL;
	ret = get_final_ret(start, expanded, rest_of_the_line);
	free(line);
	free(rest_of_the_line);
	if (!ret)
		return (NULL);
	return (ret);
}

void	breakheredoc(void)
{
	if (g_signal == 130)
	{
		rl_done = 1;
		rl_on_new_line();
	}
}
