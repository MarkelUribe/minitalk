/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:12:23 by muribe-l          #+#    #+#             */
/*   Updated: 2024/01/03 20:41:07 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*m;

	m = malloc(num * size);
	if (!m)
		return (NULL);
	ft_memset(m, 0, size * num);
	return (m);
}
/*
int main ()
{
	char *m = ft_calloc(5, sizeof(int));
}

*/