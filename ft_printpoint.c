/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpoint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalaria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:43:54 by bvalaria          #+#    #+#             */
/*   Updated: 2021/01/28 17:43:56 by bvalaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_discount(size_t n)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = n;
	if (y == 0)
		return (1);
	while (y != 0)
	{
		y = y / 16;
		x++;
	}
	return (x);
}

int	ft_pointprec(t_format var, int len, int n, int count)
{
	int i;
	int size;

	i = var.prec;
	size = len;
	if (n == 0 && var.prec == 0)
	{
		write(1, "0x", 2);
		count += 2;
	}
	while (i > size)
	{
		count = ft_print_c('0', count);
		i--;
	}
	return (count);
}

int	ft_putpointer(size_t n, int count, int len, t_format var)
{
	char	c[len];
	char	s[16];
	int		size;
	size_t	nb;

	ft_string(s, var);
	size = len;
	c[size] = '\0';
	nb = n;
	if (nb == 0 && var.prec == 0)
		return (count);
	while (size > 0)
	{
		size--;
		c[size] = s[(nb % 16)];
		nb = nb / 16;
	}
	c[0] = '0';
	c[1] = 'x';
	size = 0;
	while (c[size] != '\0')
		count = ft_print_c(c[size++], count);
	return (count);
}

int	ft_secondprintpointer(t_format var, int count, int len, size_t n)
{
	if (var.minus == 0)
	{
		if (var.zero == 1)
			var.prec = var.width;
		else
		{
			count = ft_intwidth(var.width, len, var.prec, count);
			if (n == 0 && var.prec == 0 && var.width != 0 && len < var.width)
				count = ft_print_c(' ', count);
		}
		count = ft_pointprec(var, len, n, count);
		count = ft_putpointer(n, count, len, var);
	}
	else
	{
		count = ft_pointprec(var, len, n, count);
		count = ft_putpointer(n, count, len, var);
		count = ft_intwidth(var.width, len, var.prec, count);
		if (n == 0 && var.prec == 0 && var.width != 0)
			count = ft_print_c('0', count);
	}
	return (count);
}

int	ft_printpointer(t_format var, int count, va_list ap)
{
	int		len;
	size_t	n;

	n = va_arg(ap, size_t);
	len = ft_discount(n) + 2;
	if (var.zero == 1 && (var.minus == 1 || var.prec > -1))
		var.zero = 0;
	count = ft_secondprintpointer(var, count, len, n);
	return (count);
}
