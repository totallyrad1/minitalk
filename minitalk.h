/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:39:59 by asnaji            #+#    #+#             */
/*   Updated: 2023/12/12 22:35:28 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"

int				ft_atoi(char *str);
void			print_bits(unsigned char octet);
unsigned char	reverse_bits(unsigned char octet);
void			send_bit(pid_t targetPID, int bit, int *index);

#endif