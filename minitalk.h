/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:39:59 by asnaji            #+#    #+#             */
/*   Updated: 2023/12/19 14:09:22 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <signal.h>
# include <unistd.h>

void			ft_putstr(char *str);
int				ft_atoi(char *str);
void			print_bits(unsigned char octet);
unsigned char	reverse_bits(unsigned char octet);
void			send_bit(pid_t targetPID, int bit, int *index);
unsigned char	reverse_bits(unsigned char octet);
void			ft_putchar(int c);
void			ft_putnbr(long long n);

#endif