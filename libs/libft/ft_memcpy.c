/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:45:43 by muribe-l          #+#    #+#             */
/*   Updated: 2024/01/03 20:41:52 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	void	*o_dst;

	if (src == NULL && dst == NULL)
		return (NULL);
	o_dst = dst;
	while (n > 0)
	{
		*(char *)dst = *(char *)src;
		dst++;
		src++;
		n--;
	}
	return (o_dst);
}
/*
#include <string.h>
int	main()
{
	const char src[50] = "eunooon";
   	char dest[50];
	ft_memcpy(dest, src, 5);
	printf("%s\n", dest);
   
   return(0);
}*/
