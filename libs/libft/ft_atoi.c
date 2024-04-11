/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:38:50 by muribe-l          #+#    #+#             */
/*   Updated: 2024/02/29 16:26:45 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_minmax(const char *str, int z, int sign)
{
	if (sign > 0 && z > (INT_MAX - (*str - '0')) / 10)
		return (INT_MAX);
	else if (sign < 0 && z > (INT_MIN + (*str - '0')) / -10)
		return (INT_MIN);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	z;
	int	sign;

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
/*
int	main(void)
{
	printf("%d", ft_atoi("  -3463sdfg"));
	return (0);
}
*/