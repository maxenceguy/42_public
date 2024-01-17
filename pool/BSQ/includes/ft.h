/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:57:48 by alermolo          #+#    #+#             */
/*   Updated: 2023/08/30 14:49:09 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_bsq
{
	char	*raw_map;
	char	**map;
	char	empty;
	char	obst;
	char	fill;
	int		**val_map;
	int		size;
	int		int_max;
	int		y_max;
	int		x_max;

}	t_bsq;

char	**ft_split(char *str, char *charset);
int		ft_strlen(char *str);
int		find_square(t_bsq *bsq);
int		parse_map(t_bsq *bsq, char *map_name, int ac);
void	display_map(t_bsq *bsq);
void	free_all(t_bsq *bsq);
char	*read_stdin(void);

#endif
