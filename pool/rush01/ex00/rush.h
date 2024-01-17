/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:40:42 by mguy              #+#    #+#             */
/*   Updated: 2023/08/20 16:53:54 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H
# include <unistd.h>
# include <stdlib.h>

# define SIZE 4

typedef struct data
{
	unsigned int	*key;
	unsigned int	**tab;
}	t_data;

unsigned int		parser(t_data *data, char **argv);
void				ft_putchar(char c);
void				print_table(t_data *data);
unsigned int		fill_table(t_data *data, unsigned int index);
unsigned int		check_line_left(t_data *data, unsigned int index);
unsigned int		check_line_right(t_data *data, unsigned int index);
unsigned int		check_column_top(t_data *data, unsigned int index);
unsigned int		check_column_bottom(t_data *data, unsigned int index);
unsigned int		final_check(t_data *data);

#endif
