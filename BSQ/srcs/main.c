/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:48:13 by mguy              #+#    #+#             */
/*   Updated: 2023/08/30 19:43:22 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	init_struct(t_bsq *bsq)
{
	bsq->map = NULL;
	bsq->val_map = NULL;
	bsq->raw_map = NULL;
}

int	main(int ac, char **av)
{
	int		elt;
	t_bsq	*bsq;

	elt = 1;
	if (ac == 1)
		elt = 0;
	while (elt < ac)
	{
		bsq = malloc(sizeof(t_bsq));
		if (!bsq)
			return (-1);
		init_struct(bsq);
		if (parse_map(bsq, av[elt], ac) == -1)
			write(1, "map error\n", 10);
		else
		{
			find_square(bsq);
			display_map(bsq);
		}
		if (ac > 2)
			write(1, "\n", 1);
		elt++;
		free_all(bsq);
	}
	return (0);
}
