/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:33:37 by rolamber          #+#    #+#             */
/*   Updated: 2024/06/29 15:31:05 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <stdlib.h>
#include <string.h>

static inline t_token_type	get_simple_meta(char **str)
{
	t_token_type	ret;

	ret = NONE;
	if (**str == '|')
		ret = PIPE;
	else if (**str == '<')
		ret = REDIRECT_IN;
	else if (**str == '>')
		ret = REDIRECT_OUT;
	else if (**str == '\'')
		ret = QUOTE;
	else if (**str == '\"')
		ret = DOUBLE_QUOTE;
	else if (**str == ' ')
		ret = SPACE;
	else if (**str == '\t')
		ret = TAB;
	else if (**str == '$')
		ret = DOLLAR;
	if (ret != NONE)
		(*str)++;
	return (ret);
}

static inline t_token_type	get_double_meta(char **str)
{
	t_token_type	ret;

	ret = NONE;
	if (!strncmp(*str, "<<", 2))
		ret = HEREDOC;
	else if (!strncmp(*str, ">>", 2))
		ret = APPEND;
	else if (!strncmp(*str, "$?", 2))
		ret = LAST_PROCESS_STATUS;
	if (ret != NONE)
		*str += 2;
	return (ret);
}

static size_t	get_text_len(char *str)
{
	size_t	ret;

	ret = 0;
	while (*str)
	{
		if (ft_strchr(METACHARS, *str))
			break ;
		str++;
		ret++;
	}
	return (ret);
}

static char	*get_text(char **str)
{
	char	*ret;
	size_t	len;
	size_t	i;

	len = get_text_len(*str);
	ret = ft_calloc(len + 1, sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = (*str)[i];
		i++;
	}
	(*str) += len;
	return (ret);
}

// TODO: return throw_error in case of malloc failure
t_node	*get_next_token(char *str)
{
	t_node		*ret;
	static char	*tmp = NULL;

	ret = ft_calloc(1, sizeof(t_node));
	if (!ret)
		return (NULL);
	if (!tmp)
		tmp = str;
	else if (*tmp == '\0')
	{
		tmp = NULL;
		return (ret);
	}
	ret->type = get_double_meta(&tmp);
	if (ret->type == NONE)
		ret->type = get_simple_meta(&tmp);
	if (ret->type == NONE)
	{
		ret->type = TEXT;
		ret->str = get_text(&tmp);
		if (!ret->str)
			return (free(ret), NULL);
	}
	return (ret);
}
