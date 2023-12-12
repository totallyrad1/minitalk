/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:28:25 by asnaji            #+#    #+#             */
/*   Updated: 2023/11/10 16:10:34 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_b(unsigned long l)
{
	char	add[16];
	int		i;
	int		len;
	int		res;

	i = 0;
	len = 0;
	res = 0;
	res += ft_putstr("0x");
	if (l == 0)
		add[i++] = '0';
	while (l != 0)
	{
		add[i++] = "0123456789abcdef"[l % 16];
		l = l / 16;
	}
	len = i;
	while (i-- > 0)
		res += ft_putchar(add[i]);
	return (res);
}

int	ft_printp(va_list args)
{
	unsigned char		*s;
	unsigned long long	l;

	s = va_arg(args, unsigned char *);
	l = (unsigned long long)s;
	return (ft_print_b(l));
}
