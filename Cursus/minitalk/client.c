/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:37:40 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/07/14 12:34:55 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_global;
//0x80 = 1000 0000
//1 = SIGUSR1
//0 = SIGUSR2

void	ft_handler(int signum)
{
	(void)signum;
	g_global = 0;
}

void	ft_send_message(int pid, char character)
{
	int	bit;
	int	left_bit;

	bit = 8;
	while (--bit >= 0)
	{
		g_global = 1;
		left_bit = (character >> bit) & 1;
		if (left_bit != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_global)
			usleep(1);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
		return (0);
	signal(SIGUSR1, ft_handler);
	g_global = 0;
	pid = ft_atoi(argv[1]);
	i = -1;
	while (argv[2][++i])
		ft_send_message(pid, argv[2][i]);
	return (0);
}
