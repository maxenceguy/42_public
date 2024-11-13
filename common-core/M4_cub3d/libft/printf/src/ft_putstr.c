/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxc <mxc@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:50:14 by mxc               #+#    #+#             */
/*   Updated: 2023/12/04 16:53:28 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr(char const *s, int to_free)
{
	int	len;

	if (s == NULL)
		return (ft_putstr("(null)", to_free));
	len = ft_strlen(s);
	write(1, s, len);
	if (to_free == 1)
		free((char *)s);
	return (len);
}
