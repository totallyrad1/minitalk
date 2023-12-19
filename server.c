/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:41:28 by asnaji            #+#    #+#             */
/*   Updated: 2023/12/19 17:15:12 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	printcharacter(unsigned char *mybyte, siginfo_t *data, int *n)
{
	if (*mybyte == '\0')
	{
		*n = 0;
		*mybyte = 0;
		kill(data->si_pid, SIGUSR1);
		return ;
	}
	ft_putchar(reverse_bits(*mybyte));
}

void	signalhandler(int signal, siginfo_t *data, void *useless)
{
	static unsigned char	mybyte;
	static int				currentclientpid;
	static int				n;

	(void)useless;
	if (currentclientpid != data->si_pid)
	{
		n = 0;
		mybyte = 0;
		currentclientpid = data->si_pid;
	}
	if (signal == SIGUSR1 && n != 8)
		mybyte |= (1 << n++);
	else if (signal == SIGUSR2 && n != 8)
		mybyte |= (0 << n++);
	if (n == 8)
	{
		printcharacter(&mybyte, data, &n);
		n = 0;
		mybyte = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					serverpid;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signalhandler;
	serverpid = getpid();
	ft_putstr("this is the pid : ");
	ft_putnbr(serverpid);
	ft_putstr(" \n");
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
