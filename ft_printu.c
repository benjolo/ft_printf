/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalaria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:48:45 by bvalaria          #+#    #+#             */
/*   Updated: 2021/01/26 15:48:48 by bvalaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_unsgetorder(unsigned int nb)
{
	int				order;
	int				i;
	unsigned int	n;

	order = 1;
	i = 0;
	n = nb;
	if (n == 0)
		return (1);
	while (n / order != 0)
	{
		order *= 10;
		i++;
		if (order > 1000000000)
			return (i);
	}
	return (i);
}

int	ft_unsintprec(int prec, int len, int count)
{
	int i;
	int size;

	i = prec;
	size = len;
	while (i > size)
	{
		count = ft_print_c('0', count);
		i--;
	}
	return (count);
}

int	ft_putunsignednbr(unsigned int nb, int count, t_format var)
{
	int				i;
	unsigned int	n;

	n = nb;
	i = 1000000000;
	if (nb == 0 && var.prec != 0)
	{
		write(1, "0", 1);
		count++;
	}
	else if (nb == 0 && var.prec == 0)
		return (count);
	else
	{
		while (n / i == 0)
			i = i / 10;
		while (i != 1)
		{
			count = ft_print_c(((char)(n / i) + '0'), count);
			n = n - (i * (n / i));
			i = i / 10;
		}
		count = ft_print_c(((char)(n % 10) + '0'), count);
	}
	return (count);
}

int	ft_secondprintu(t_format var, int count, int len, unsigned int n)
{
	if (var.minus == 0)
	{
		if (var.zero == 1 && n == 0 && var.width == 0 && var.prec == -1)
			return (ft_print_c('0', count));
		else if (var.zero == 1)
			var.prec = var.width;
		else
		{
			count = ft_intwidth(var.width, len, var.prec, count);
			if (n == 0 && var.prec == 0 && var.width != 0)
				count = ft_print_c(' ', count);
		}
		count = ft_unsintprec(var.prec, len, count);
		count = ft_putunsignednbr(n, count, var);
	}
	else
	{
		count = ft_unsintprec(var.prec, len, count);
		count = ft_putunsignednbr(n, count, var);
		count = ft_intwidth(var.width, len, var.prec, count);
		if (n == 0 && var.prec == 0 && var.width != 0)
			count = ft_print_c(' ', count);
	}
	return (count);
}

int	ft_printu(t_format var, int count, va_list ap)
{
	unsigned int	n;
	int				len;

	n = va_arg(ap, unsigned int);
	len = ft_unsgetorder(n);
	if (var.zero == 1 && (var.minus == 1 || var.prec > -1))
		var.zero = 0;
	count = ft_secondprintu(var, count, len, n);
	return (count);
}
