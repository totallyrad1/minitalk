/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:22:52 by asnaji            #+#    #+#             */
/*   Updated: 2023/11/11 18:05:02 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	detectcharafterperc(const char *s, int i, va_list args)
{
	if (s[i])
	{
		if (s[i] == 'c')
			return (ft_printc(args));
		else if (s[i] == 's')
			return (ft_prints(args));
		else if (s[i] == 'd' || s[i] == 'i')
			return (ft_printid(args));
		else if (s[i] == 'u')
			return (ft_printu(args));
		else if (s[i] == 'p')
			return (ft_printp(args));
		else if (s[i] == 'x')
			return (ft_printxx(args, 0));
		else if (s[i] == 'X')
			return (ft_printxx(args, 1));
		else
			return (ft_putchar(s[i]));
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		r;

	va_start(args, s);
	i = 0;
	r = 0;
	if (write(1, "", 0) < 0)
		return (-1);
	while (s[i])
	{
		if (s[i] == '%')
		{
			r += detectcharafterperc(s, i + 1, args);
			i++;
		}
		else
			r += ft_putchar(s[i]);
		if (s[i])
			i++;
	}
	va_end(args);
	return (r);
}
