/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:43:01 by muribe-l          #+#    #+#             */
/*   Updated: 2024/01/03 20:44:43 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	s;
	size_t	i;

	i = 0;
	s = ft_strlen(src);
	if (dstsize < 1)
		return (s);
	while (dstsize - 1 > i && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (s);
}
/*
int main()
{
    char str[]= "kaixooooooooo";
    char str2[] = "eunonaaaa";
    int s;

    s = strlcpy(str, str2, 6);
    printf("%s\n%d", str, s);

    return 0;
}*/
