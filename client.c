/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:54:12 by muribe-l          #+#    #+#             */
/*   Updated: 2024/04/22 15:55:20 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	send(int pid, char *msg)
{
	int		i;
	unsigned char	c;

	while (*msg)
	{
		i = 8;
		c = *msg;
		while (i-- >= 0)
		{
			if ((c >> i) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(75);
			usleep(75);
		}
		msg++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		send(ft_atoi(argv[1]), argv[2]);
	return (0);
}