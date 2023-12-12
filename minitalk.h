/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:39:59 by asnaji            #+#    #+#             */
/*   Updated: 2023/12/11 17:02:39 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdio.h>

int				ft_atoi(const char *str);
void			print_bits(unsigned char octet);
unsigned char	reverse_bits(unsigned char octet);

#endif