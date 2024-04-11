/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:12:49 by muribe-l          #+#    #+#             */
/*   Updated: 2024/01/11 11:24:12 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;
	size_t	actual_len;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	actual_len = ft_strlen(s + start);
	if (actual_len > len)
		actual_len = len;
	str = (char *)malloc(sizeof(char) * actual_len + 1);
	if (!str || !s)
		return (NULL);
	i = 0;
	while ((int)actual_len > i && s[start] != '\0')
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
/*
int	main()
{
}*/