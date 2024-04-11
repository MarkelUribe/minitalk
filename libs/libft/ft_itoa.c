/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:03:03 by muribe-l          #+#    #+#             */
/*   Updated: 2024/01/11 12:38:37 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*loop(char *s, int n, int digits, int minus)
{
	s[digits] = '\0';
	if (minus)
		s[0] = '-';
	while (digits > minus)
	{
		s[digits - 1] = (n % 10) + '0';
		n /= 10;
		digits--;
	}
	return (s);
}

static int	counter(int temp, int digits)
{
	while (temp)
	{
		digits++;
		temp /= 10;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		digits;
	int		minus;
	int		temp;

	digits = 0;
	minus = 0;
	temp = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648\0"));
	if (n <= 0)
	{
		digits = 1;
		if (n < 0)
		{
			minus = 1;
			n = -n;
			temp = n;
		}
	}
	digits = counter(temp, digits);
	s = (char *)malloc(sizeof(char) * digits + 1);
	if (!s)
		return (NULL);
	return (loop(s, n, digits, minus));
}
//
// int main()
// {	
// 	char	*s;
// 	s = ft_itoa(0);
// 	printf("%s\n", s);
// 	free(s);
// }
//