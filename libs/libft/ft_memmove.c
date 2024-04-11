/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:49:06 by muribe-l          #+#    #+#             */
/*   Updated: 2024/01/03 20:42:00 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s1;
	char	*s2;

	s1 = (char *)dst;
	s2 = (char *)src;
	if (!dst && !src)
		return (0);
	if (dst > src)
	{
		while (len--)
			s1[len] = s2[len];
	}
	else
		ft_memcpy(dst, src, len);
	return (s1);
}
/*
#include <string.h>
int	main()
{
	const char src[50] = "eunooon";
   	char dest[50] =  "zezeaaaa";
	memmove(dest, src, 5);
	printf("%s\n", dest);

   return(0);
}
*/