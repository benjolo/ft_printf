/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalaria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:51:23 by bvalaria          #+#    #+#             */
/*   Updated: 2021/01/26 15:51:25 by bvalaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_isdigit(int c)
{
	unsigned char x;

	x = (unsigned char)c;
	if (c < 0 || c > 255)
		return (0);
	if (x >= '0' && x <= '9')
		return (1);
	else
		return (0);
}

int	ft_print_c(char c, int count)
{
	write(1, &c, 1);
	return (count + 1);
}

int	ft_print_sp(int n, int count)
{
	int		i;

	i = 0;
	while (i < n - 1)
	{
		count = ft_print_c(' ', count);
		i++;
	}
	return (count);
}

int	ft_printchar(t_format var, int count, va_list ap)
{
	int		x;
	char	c;

	x = va_arg(ap, int);
	c = (char)x;
	if (var.width > 0)
	{
		if (var.minus == 1)
		{
			count = ft_print_c(c, count);
			count = ft_print_sp(var.width, count);
		}
		else
		{
			count = ft_print_sp(var.width, count);
			count = ft_print_c(c, count);
		}
	}
	else
		count = ft_print_c(c, count);
	return (count);
}
