/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:53:18 by muribe-l          #+#    #+#             */
/*   Updated: 2023/12/19 14:48:32 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	r = (char *)malloc(len_s1 + len_s2 + 1);
	if (!r)
		return (NULL);
	ft_strlcpy(r, s1, len_s1 + 1);
	ft_strlcat(r, s2, len_s1 + len_s2 + 1);
	return (r);
}
