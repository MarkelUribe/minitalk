/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:17:47 by muribe-l          #+#    #+#             */
/*   Updated: 2024/02/29 12:25:01 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	void	*set;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		set = f(lst->nbr);
		tmp = ft_lstnew(set);
		if (!tmp)
		{
			del(set);
			ft_lstclear(&new, (*del));
			return (new);
		}
		ft_lstadd_back(&new, tmp);
		lst = lst->next;
	}
	return (new);
}
