/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:45:45 by mguy              #+#    #+#             */
/*   Updated: 2024/01/17 08:54:26 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include "../libft.h"

int		ft_printf(const char *s, ...);
int		ft_putchar(int c);
int		ft_putstr(char const *s, int to_free);
int		ft_hexa(unsigned int n, int i);
char	*ft_utoa(unsigned int num);
int		ft_pointer(unsigned long long ptr);

#endif
