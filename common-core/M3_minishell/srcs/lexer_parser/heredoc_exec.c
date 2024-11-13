/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:43:03 by rolamber          #+#    #+#             */
/*   Updated: 2024/07/24 19:23:16 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*join_expanded_line(char *rest_ofline, char *sub_exp, char *start)
{
	char	*ret;

	ret = ft_strjoin(start, sub_exp);
	if (!ret)
		return (free(start), free(rest_ofline), NULL);
	free(start);
	start = ret;
	ret = ft_strjoin(start, rest_ofline);
	if (!ret)
		return (free(start), free(rest_ofline), NULL);
	free(start);
	free(rest_ofline);
	return (ret);
}

static char	*get_expanded_line(char *line, char *dollar_pos, char *sub_expand)
{
	char	*ret;
	char	*start;
	char	*rest_of_the_line;
	int		i;

	if (line != dollar_pos)
		start = ft_substr(line, 0, dollar_pos - line);
	else
		start = ft_strdup("");
	if (!start)
		return (NULL);
	i = 0;
	while (dollar_pos[i] && !ft_strchr(METACHARS, dollar_pos[i]))
		i++;
	if (i == 0)
		rest_of_the_line = ft_strdup("");
	else
		rest_of_the_line = ft_strdup(dollar_pos + i);
	if (!rest_of_the_line)
		return (free(start), NULL);
	ret = join_expanded_line(rest_of_the_line, sub_expand, start);
	if (!ret)
		return (NULL);
	return (ret);
}

static char	*create_sub_expand(char *line, t_gen *gen)
{
	int		i;
	char	*ret;
	char	*temp;

	i = 0;
	while (line[i] && !ft_strchr(METACHARS, line[i]))
		i++;
	temp = ft_substr(line, 0, i);
	if (!temp)
		return (NULL);
	ret = ft_getenv(gen->env, temp);
	if (!ret)
	{
		free(temp);
		return (NULL);
	}
	free(temp);
	return (ret);
}

char	*heredoc_expand(char *line, t_gen *gen)
{
	char	*ret;
	char	*tmp;
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '$' && line[i + 1] == '?')
			line = heredoc_expand_last_process(line, i, gen);
		else if (line[i] == '$' && !ft_strchr(METACHARS, line[i + 1]))
		{
			tmp = create_sub_expand(&line[i + 1], gen);
			if (!tmp)
				return (NULL);
			ret = get_expanded_line(line, &line[i], tmp);
			if (!ret)
				return (free(tmp), NULL);
			i += (ft_strlen(tmp) - 1);
			line = ret;
		}
		i++;
	}
	return (line);
}

t_node	*heredoc(t_node *node, bool flag, t_gen *gen)
{
	static char	filename = 'a';
	int			temp_fd;

	filename++;
	temp_fd = open(&filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (temp_fd < 0)
	{
		perror("open");
		return (NULL);
	}
	gen->node = node;
	if (!write_here_file(gen, temp_fd, flag))
	{
		node->fd = ft_strdup(&filename);
		if (!node->fd)
			return (NULL);
		close(temp_fd);
		return (NULL);
	}
	node->fd = ft_strdup(&filename);
	if (!node->fd)
		return (NULL);
	close(temp_fd);
	return (node);
}
