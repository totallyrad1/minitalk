/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:41:28 by asnaji            #+#    #+#             */
/*   Updated: 2023/12/12 14:05:56 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <stdio.h>
#include <sys/_types/_null.h>
#include <sys/signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_atoi(char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	res;
	int		count;

	res = 0;
	count = 8;
	while (count)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		count--;
	}
	return (res);
}

void signalhandler(int signal)
{
    static unsigned char myByte = 0;
    static int n = 0;
    if (signal == SIGUSR1 && n != 8)
    {
        myByte |= (1 << n);
        n++;
    }
    else if (signal == SIGUSR2 && n != 8)
    {
        myByte |= (0 << n);
        n++;
    }
    if (n == 8)
    {
        ft_printf("%c", reverse_bits(myByte));
        n = 0;
        myByte = 0;
    }
}


int main()
{
	pid_t currentPID = getpid();
	ft_printf("this is the pid : %d \n", currentPID);

	struct sigaction sa;
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = signalhandler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while(0 == 0)
	{
	}
}