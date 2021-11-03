/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalaria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:49:52 by bvalaria          #+#    #+#             */
/*   Updated: 2021/01/26 15:49:54 by bvalaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_rightputnbr(int nb, int count)
{
	int i;
	int n;

	n = nb;
	i = 1000000000;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n / i == 0)
		i = i / 10;
	while (i != 1)
	{
		count = ft_print_c(((char)(n / i) + '0'), count);
		n = n - (i * (n / i));
		i = i / 10;
	}
	count = ft_print_c(((char)(n % 10) + '0'), count);
	return (count);
}

int	ft_putnbr(int nb, int count, t_format var)
{
	if (nb == 0 && var.zero == 1)
		count = ft_print_c('0', count);
	else if (nb == 0 && var.prec == 0)
		return (count);
	else if (nb == 0 && var.prec != 0)
		count = ft_print_c('0', count);
	else
		count = ft_rightputnbr(nb, count);
	return (count);
}

int	ft_minmaxint(int n, t_format var, int count)
{
	if ((long int)n == 2147483648 || (long int)n == -2147483648)
	{
		if (n < 0)
			var.width--;
		if (var.zero == 1 && (var.minus == 1 || var.prec > -1))
			var.zero = 0;
		if (var.minus == 0)
		{
			if (var.zero == 1)
				var.prec = var.width;
			else
				count = ft_intwidth(var.width, 10, var.prec, count);
			count = ft_intprec(var.prec, 10, n, count) + 10;
			write(1, "2147483648", 10);
		}
		else
		{
			count = ft_intprec(var.prec, 10, n, count);
			write(1, "2147483648", 10);
			count = ft_intwidth(var.width, 10, var.prec, count) + 10;
		}
	}
	return (count);
}

int	ft_secondinteger(t_format var, int count, int len, int n)
{
	if (var.minus == 0)
	{
		if (var.zero == 1)
			var.prec = var.width;
		else
		{
			count = ft_intwidth(var.width, len, var.prec, count);
			if (n == 0 && var.prec == 0 && var.width != 0)
				count = ft_print_c(' ', count);
		}
		count = ft_intprec(var.prec, len, n, count);
		count = ft_putnbr(n, count, var);
	}
	else
	{
		count = ft_intprec(var.prec, len, n, count);
		count = ft_putnbr(n, count, var);
		count = ft_intwidth(var.width, len, var.prec, count);
		if (n == 0 && var.prec == 0 && var.width != 0)
			count = ft_print_c(' ', count);
	}
	return (count);
}

int	ft_printinteger(t_format var, int count, va_list ap)
{
	int n;
	int	len;

	n = va_arg(ap, int);
	if (!((long int)n == 2147483648 || (long int)n == -2147483648))
	{
		if (n < 0 || n > 2147483647)
			var.width--;
		len = ft_getorder(n);
		if (var.zero == 1 && (var.minus == 1 || var.prec > -1))
			var.zero = 0;
		count = ft_secondinteger(var, count, len, n);
	}
	else
		count = ft_minmaxint(n, var, count);
	return (count);
}
