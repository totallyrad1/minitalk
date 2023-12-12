/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:41:11 by asnaji            #+#    #+#             */
/*   Updated: 2023/12/12 14:09:54 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

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

void send_bit(pid_t targetPID, int bit,int *index)
{
	int i;
    if (bit)
        {	
			i = kill(targetPID, SIGUSR1);
			if(i == -1)
				*index =1;
		}
    else
        {
			i =  kill(targetPID, SIGUSR2);
			if(i == -1)
				*index = 1;
		};
}

int main(int ac, char **av)
{
	int i = 0;
	int j;
    pid_t targetPID = atoi(av[1]);
    char *message = av[2];
	int index = 0;
	if(ac == 3)
	{
		while(message[i])
		{
			j = 7;
			while(j >= 0)
			{
				send_bit(targetPID, message[i] >> j & 1, &index);
				if(index == 1)
				{
					ft_printf("error no signal sent");
					return 0;
				}
				usleep(800);
				j--;
			}
			i++;
		}
	}

    return 0;
}