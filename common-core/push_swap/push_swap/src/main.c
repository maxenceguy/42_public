/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxc <mxc@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:14:32 by mxc               #+#    #+#             */
/*   Updated: 2024/02/09 00:02:03 by mxc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_list	*list_a;
	t_list	*list_b;
	int		len;

	if (ac < 2)
		return (0);
	list_a = get_list(ac, av);
	list_b = NULL;
	len = get_len(&list_a);
	get_pos(&list_a);
	if (len == 0 || verif_sort(&list_a))
		return (free_list(&list_a), free_list(&list_b), 0);
	else if (len == 2 && (list_a)->value > (list_a)->next->value)
		do_s(&list_a, "sa\n");
	else if (len == 3)
		sort_three(&list_a, 'a');
	else
		sort(&list_a, &list_b);
	return (free_list(&list_a), free_list(&list_b), 0);
}
