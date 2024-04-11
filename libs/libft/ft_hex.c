/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:25:08 by muribe-l          #+#    #+#             */
/*   Updated: 2024/02/15 12:11:52 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hex(long nbr, char *base)
{
	int	i;

	i = 0;
	if (nbr < 16)
	{
		write(1, &base[nbr % 16], 1);
		return (1);
	}
	if (nbr > 0)
	{
		i = ft_hex(nbr / 16, base);
		write(1, &base[nbr % 16], 1);
	}
	return (i + 1);
}
