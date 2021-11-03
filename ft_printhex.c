/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalaria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:47:57 by bvalaria          #+#    #+#             */
/*   Updated: 2021/01/26 15:48:00 by bvalaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_count(unsigned int n)
{
	unsigned int		x;
	unsigned int		y;

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

void	ft_string(char *s, t_format var)
{
	s[0] = '0';
	s[1] = '1';
	s[2] = '2';
	s[3] = '3';
	s[4] = '4';
	s[5] = '5';
	s[6] = '6';
	s[7] = '7';
	s[8] = '8';
	s[9] = '9';
	s[10] = 'a';
	s[11] = 'b';
	s[12] = 'c';
	s[13] = 'd';
	s[14] = 'e';
	s[15] = 'f';
	if (var.type == 'X')
	{
		s[10] = 'A';
		s[11] = 'B';
		s[12] = 'C';
		s[13] = 'D';
		s[14] = 'E';
		s[15] = 'F';
	}
}

int		ft_puthexnbr(unsigned int n, int count, int len, t_format var)
{
	char			c[9];
	char			s[16];
	int				size;
	unsigned int	nb;

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
		count++;
		nb = nb / 16;
	}
	while (c[size] != '\0')
	{
		write(1, &c[size], 1);
		size++;
	}
	return (count);
}

int		ft_secondprinthex(t_format var, int count, int len, unsigned int n)
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
		count = ft_puthexnbr(n, count, len, var);
	}
	else
	{
		count = ft_unsintprec(var.prec, len, count);
		count = ft_puthexnbr(n, count, len, var);
		count = ft_intwidth(var.width, len, var.prec, count);
		if (n == 0 && var.prec == 0 && var.width != 0)
			count = ft_print_c(' ', count);
	}
	return (count);
}

int		ft_printhex(t_format var, int count, va_list ap)
{
	int					len;
	unsigned int		n;

	n = va_arg(ap, unsigned int);
	len = ft_count(n);
	if (var.zero == 1 && (var.minus == 1 || var.prec > -1))
		var.zero = 0;
	count = ft_secondprinthex(var, count, len, n);
	return (count);
}
