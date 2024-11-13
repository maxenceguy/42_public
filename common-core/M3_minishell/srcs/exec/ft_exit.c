/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:04:53 by mguy              #+#    #+#             */
/*   Updated: 2024/07/30 15:09:38 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	display_exit(int error, char *msg, t_gen *gen)
{
	gen->error_code = error;
	printf("%s\n", msg);
	ft_exit(gen);
}

void	error_exit(int error_code, t_gen *gen)
{
	gen->error_code = error_code;
	ft_exit(gen);
}

int	ft_exit(t_gen *gen)
{
	int	ret;

	ret = gen->error_code;
	free_cmd(gen);
	free_list(gen->env);
	free(gen);
	exit(ret);
	return (0);
}
