/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 06:54:14 by mguy              #+#    #+#             */
/*   Updated: 2024/01/18 08:36:34 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_int_max(char const *s)
{
	if (s[0] == '-')
		return (0);
	if (ft_strlen(s) >= 10 && (s[0] > '2' || s[1] > '1' || s[2] > '4'
			|| s[3] > '7' || s[4] > '4' || s[5] > '8' || s[6] > '3'
			|| s[7] > '6' || s[8] > '4' || s[9] > '7'))
		return (1);
	return (0);
}
