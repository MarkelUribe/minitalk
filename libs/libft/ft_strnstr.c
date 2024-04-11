/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:18:18 by muribe-l          #+#    #+#             */
/*   Updated: 2024/01/03 20:44:59 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (*haystack != '\0' && len > 0)
	{
		if (*haystack == needle[i])
		{
			i++;
			if (needle[i] == '\0')
				return ((char *)haystack - i + 1);
		}
		else
		{
			haystack -= i;
			len = len + i;
			i = 0;
		}
		haystack++;
		len--;
	}
	return (NULL);
}
/*
#include <string.h>
int main()
{
	char *h = "kaixoe gooounon zer moduz";
	char *n = "oou";
	printf("%s", ft_strnstr(h, n, 50));
}
*/