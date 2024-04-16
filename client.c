/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:54:12 by muribe-l          #+#    #+#             */
/*   Updated: 2024/04/16 16:18:17 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	send(int pid, char *msg)
{
	int		i;
	char	c;

	while (*msg)
	{
		i = 0;
		c = *msg;
		while (i < 8)
		{
			if (c & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			i++;
			c = c >> 1;
		}
		msg++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		send(pid, argv[2]);
	}
	return (0);
}