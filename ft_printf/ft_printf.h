/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:15:10 by asnaji            #+#    #+#             */
/*   Updated: 2023/11/10 14:28:46 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
int		ft_printc(va_list args);
int		ft_prints(va_list args);
int		ft_printid(va_list args);
int		ft_printu(va_list args);
int		ft_printp(va_list args);
int		ft_printxx(va_list args, int i);

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		countintlen(long nb);
int		ft_putnbr(long long n);
int		countintlenbase(unsigned int nb);

#endif