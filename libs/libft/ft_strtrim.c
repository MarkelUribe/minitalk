/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:38:39 by muribe-l          #+#    #+#             */
/*   Updated: 2024/01/03 20:45:04 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		j;
	int		start;
	int		end;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	str = (char *)malloc(end - start + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (start < end)
	{
		str[j] = s1[start];
		start++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
/*
int	main()
{
	char *s = "kaixoooo zer moduz";
	char *s1 = "kodfgh";

	printf("%s", ft_strtrim(s, s1));
}*/