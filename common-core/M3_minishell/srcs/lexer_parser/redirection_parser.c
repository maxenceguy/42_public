/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_parser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:00:14 by rolamber          #+#    #+#             */
/*   Updated: 2024/07/13 17:01:35 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// count words and return a boolean if there is more than one word
static bool	is_ambiguous(t_node *node)
{
	int		i;
	char	*temp;
	int		words;

	words = 0;
	temp = node->str;
	i = 0;
	while (temp[i])
	{
		while (temp[i] == ' ' || temp[i] == '\t')
			i++;
		if (temp[i] != ' ' && temp[i] != '\t' && temp[i] != '\0')
		{
			words++;
			while (temp[i] != ' ' && temp[i] != '\t' && temp[i] != '\0')
				i++;
		}
	}
	if (words > 1)
		return (true);
	return (false);
}
// return the next node after the redirect token fusion, check amgiuous redirect

static t_node	*get_redirect_token(t_node *node)
{
	t_node	*tmp;

	tmp = node;
	node = node->next;
	while (node->type == SPACE || node->type == TAB)
	{
		node = node->next;
		pop_node(node->prev);
	}
	if (node->type == EXPANDED_TEXT || node->type == TEXT)
	{
		if (is_ambiguous(node) && node->type == EXPANDED_TEXT)
		{
			printf("minishell: ambiguous redirect\n");
			tmp->code_error = 1;
			tmp->access_error = true;
		}
		tmp->str = ft_strdup(node->str);
		if (!tmp->str)
			return (NULL);
		pop_node(node);
	}
	return (tmp);
}

static void	redirection_in(t_node *node)
{
	if (access(node->str, F_OK) != 0)
	{
		node->access_error = true;
		printf(" 1\"%s\" does not exist\n", node->str);
		node->code_error = 1;
		return ;
	}
	if (access(node->str, W_OK) != 0 || access(node->str, R_OK) != 0)
	{
		node->access_error = true;
		printf("2\"%s\" permission denied\n", node->str);
		node->code_error = 1;
	}
	if (node->code_error != 1)
		node->fd = node->str;
}

static void	redirection_out(t_node *node)
{
	if (access(node->str, F_OK) != 0)
		create_outfile(node);
	if (access(node->str, W_OK) != 0 || access(node->str, R_OK) != 0)
	{
		node->access_error = true;
		printf("3\"%s\" permission denied\n", node->str);
		node->code_error = 1;
	}
	if (node->code_error != 1)
		node->fd = node->str;
}

// fusion redirect token with the next text token
t_node	*redirection_parser(t_node *node)
{
	while (node->type != NONE)
	{
		if (node->type == REDIRECT_IN)
		{
			node = get_redirect_token(node);
			if (!node)
				return (NULL);
			redirection_in(node);
		}
		else if (node->type == REDIRECT_OUT || node->type == APPEND)
		{
			node = get_redirect_token(node);
			if (!node)
				return (NULL);
			redirection_out(node);
		}
		node = node->next;
	}
	return (head_node(node));
}
