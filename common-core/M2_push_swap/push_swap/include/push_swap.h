/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:32:12 by mguy              #+#    #+#             */
/*   Updated: 2024/02/09 13:20:48 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				value;
	int				pos;
	struct s_list	*next;
}	t_list;

typedef struct s_param
{
	int	top;
	int	len_b;
	int	len_a;
	int	max;
	int	rotate;
	int	global_max;
	int	round;
	int	min;
	int	max_lb;
}	t_param;

// main.c
int		main(int ac, char **av);

// node.c
t_list	*new_node(t_list **list_a, int value);
t_list	**node_top(t_list **list, t_list *node);
t_list	**node_bottom(t_list **list, t_list *node);

// sort.c
void	manage_round(t_list **l_a, t_list **l_b, t_param *p);
void	push_optimized(t_list **l_a, t_list **l_b, t_param *p);
int		sort_a(t_list **l_a, t_list **l_b, t_param *p);
void	sort(t_list **l_a, t_list **l_b);

// sort_short.c
void	sort_three(t_list **list, char ab);
int		is_pos_sup(int bot_a, t_list **l_b);
void	spe_sort(t_list **l_a, t_list **l_b);

// find.c
int		find_min(t_list **list_a);
int		find_max(t_list **list);
int		find_min_pos(t_list **list);
int		find_max_pos(t_list **list);
int		find_fast(int pos, t_list **list, int len);

// actions.c
void	do_r(t_list **list, char *txt);
void	do_rr(t_list **list, char *txt);
void	do_push(t_list **dest, t_list **src, char *txt);
void	do_s(t_list **list, char *txt);
void	push_max(t_list **l_a, t_list **l_b);

// utils.c
t_list	*get_list(int ac, char **av);
int		bottom_value(t_list **list);
int		bottom_pos(t_list **list);
int		verif_sort(t_list **list);

// utils2.c
int		get_len(t_list **list);
void	min_on_top(t_list **list);
void	push_min(t_list **l_a, t_list **l_b, int min);
void	print_list(t_list **list);

// positions.c
int		find_max_empty_pos(t_list **list);
void	get_pos(t_list **list);

// end.c
void	free_list(t_list **list);
void	free_args(char **args);
void	exit_error(t_list **list_a, t_list **list_b);
int		check_params(char **args);
int		check_int(char *param);

#endif
