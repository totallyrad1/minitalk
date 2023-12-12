/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:41:11 by asnaji            #+#    #+#             */
/*   Updated: 2023/12/12 10:42:05 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <string.h>
#include <stdlib.h>
#include <sys/signal.h>

int	ft_atoi(const char *str)
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

void send_bit(pid_t targetPID, int bit)
{
    if (bit)
        kill(targetPID, SIGUSR1);
    else
        kill(targetPID, SIGUSR2);
	usleep(800);
}

int main(int ac, char **av)
{
	int i = 0;
	int j;
    pid_t targetPID = atoi(av[1]);
    char *message = av[2];
	char c = 'c';
	if(ac == 3)
	{
		while(message[i])
		{
			j = 7;
			c = message[i];
			while(j >= 0)
			{
				int bit = (c >> j) & 1;
				send_bit(targetPID, bit);
				j--;
			}
			i++;
		}
	}

    return 0;
}