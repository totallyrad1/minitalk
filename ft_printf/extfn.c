/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extfn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:42:23 by asnaji            #+#    #+#             */
/*   Updated: 2023/11/10 14:16:10 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (s[i])
	{
		res += ft_putchar(s[i++]);
	}
	return (res);
}

int	countintlen(long nb)
{
	int	i;
	int	neg;

	i = 0;
	neg = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		neg = 1;
	}
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i + neg);
}

int	ft_putnbr(long long n)
{
	long long	nb;
	int			res;
	int			neg;

	nb = n;
	res = 0;
	neg = 0;
	if (nb < 0)
	{
		res += ft_putchar('-');
		nb *= -1;
		neg = 1;
	}
	if (nb > 9)
	{
		res += ft_putnbr(nb / 10);
		res += ft_putnbr(nb % 10);
	}
	if (nb >= 0 && nb <= 9)
		res += ft_putchar(nb + 48);
	return (res);
}

int	countintlenbase(unsigned int nb)
{
	int	i;
	int	neg;

	i = 0;
	neg = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		neg = 1;
	}
	while (nb > 0)
	{
		nb /= 16;
		i++;
	}
	return (i + neg);
}
