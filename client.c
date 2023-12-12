/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:41:11 by asnaji            #+#    #+#             */
/*   Updated: 2023/12/12 22:16:11 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sendbackslah(int targetpid)
{
	char	c;	
	int		j;	
	int		index;	

	j = 7;
	index = 0;
	c = '\0';
	while (j >= 0)
	{
		send_bit(targetpid, c >> j & 1, &index);
		if (index == 1)
		{
			ft_printf("\nCouldnt send the message check the pid");
			exit(0);
		}
		usleep(300);
		j--;
	}
}

void	sendmessage(int targetpid, char *message)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	j = 0;
	index = 0;
	while (message[i])
	{
		j = 7;
		while (j >= 0)
		{
			send_bit(targetpid, message[i] >> j & 1, &index);
			if (index == 1)
			{
				ft_printf("Couldnt send the message check the pid");
				exit(0);
			}
			usleep(300);
			j--;
		}
		i++;
	}
	sendbackslah(targetpid);
}

void	printmessage(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Message sent successfully !!");
}

void	send_bit(pid_t targetPID, int bit, int *index)
{
	int	i;

	i = 0;
	if (bit)
	{
		i = kill(targetPID, SIGUSR1);
		if (i == -1)
			*index = 1;
	}
	else
	{
		i = kill(targetPID, SIGUSR2);
		if (i == -1)
			*index = 1;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		signal(SIGUSR1, printmessage);
		sendmessage(ft_atoi(av[1]), av[2]);
	}
}
