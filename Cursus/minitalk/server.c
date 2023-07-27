/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:37:47 by jsaavedr          #+#    #+#             */
/*   Updated: 2023/07/14 12:28:36 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
//1 = SIGUSR1
//0 = SIGUSR2
void	ft_handler(int signum, siginfo_t *info, void *context)
{
	static int	bit = 8;
	static char	character = 0;

	kill(info->si_pid, SIGUSR1);
	bit--;
	(void)context;
	if (signum == SIGUSR1)
		character = character | (1 << bit);
	if (bit == 0)
	{
		bit = 8;
		ft_printf("%c", character);
		character = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	sa.sa_sigaction = ft_handler;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("pid: %d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
