/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_Xx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:28:26 by asnaji            #+#    #+#             */
/*   Updated: 2023/11/09 15:35:32 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_base(long long n, char *base, int len, char *result)
{
	long long	nb;
	int			neg;
	int			ln;

	nb = n;
	neg = 0;
	if (nb < 0)
	{
		neg = 1;
		nb *= -1;
	}
	ln = len + neg;
	if (neg == 1)
		result[0] = '-';
	result[ln] = '\0';
	while (ln > neg)
	{
		result[ln-- - 1] = base[nb % 16];
		nb = nb / 16;
	}
	ln = ft_putstr(result);
	return (ln);
}

int	ft_printxx(va_list args, int i)
{
	unsigned int		l;
	char				*basex;
	char				*basexc;
	char				result[16];

	basex = "0123456789abcdef";
	basexc = "0123456789ABCDEF";
	l = va_arg(args, unsigned int);
	if (i)
		return (ft_putnbr_base(l, basexc, countintlenbase(l), result));
	return (ft_putnbr_base(l, basex, countintlenbase(l), result));
}
