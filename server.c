/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:48:40 by muribe-l          #+#    #+#             */
/*   Updated: 2024/04/18 16:18:19 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	g_bit;

static void	get_signal(int signal)
{
	if (signal == SIGUSR1)
		g_bit = 0;
	else if (signal == SIGUSR2)
		g_bit = 1;
}

void	decode()
{
	int		i;
	char	c;

	i = 7;
	c = 0;
	while (i >= 0)
	{
		pause();
		ft_printf("%d", g_bit);
		g_bit = g_bit << i;
		c = c | g_bit;
		i--;
	}
	ft_printf("%c", c);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("%i\n", pid);
	signal(SIGUSR1, get_signal);
	signal(SIGUSR2, get_signal);
	while (1)
		decode();
	return (0);
}
