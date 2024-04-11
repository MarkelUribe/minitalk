/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:30:56 by muribe-l          #+#    #+#             */
/*   Updated: 2024/02/28 13:32:32 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	check_minmax(const char *str, long z, int sign)
{
	if (sign > 0 && z > (LONG_MAX - (*str - '0')) / 10)
		return (LONG_MAX);
	else if (sign < 0 && z > (LONG_MIN + (*str - '0')) / -10)
		return (LONG_MIN);
	return (0);
}

long	ft_atol(const char *str)
{
	long	z;
	int		sign;

	z = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\r' || *str == '\f')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		if (check_minmax(str, z, sign))
			return (check_minmax(str, z, sign));
		z *= 10;
		z += *str - '0';
		str++;
	}
	return (z * sign);
}
