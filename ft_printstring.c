/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalaria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:03:15 by bvalaria          #+#    #+#             */
/*   Updated: 2021/01/22 16:03:20 by bvalaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_putstr(char *str, int count, t_format var)
{
	int i;

	i = 0;
	if (var.prec == -1)
	{
		while (str[i] != '\0')
		{
			count = ft_print_c(str[i], count);
			i++;
		}
	}
	else if (var.prec >= 0)
	{
		while (str[i] != '\0' && i < var.prec)
		{
			count = ft_print_c(str[i], count);
			i++;
		}
	}
	return (count);
}

int	ft_ft_print_space(int count, int k, t_format var)
{
	while (k < var.width)
	{
		count = ft_print_c(' ', count);
		k++;
	}
	return (count);
}

int	ft_printnull(int count, int k)
{
	char	s[7];
	int		i;

	s[0] = '(';
	s[1] = 'n';
	s[2] = 'u';
	s[3] = 'l';
	s[4] = 'l';
	s[5] = ')';
	s[6] = '\0';
	i = 0;
	while (k > 0 && s[i])
	{
		count = ft_print_c(s[i], count);
		k--;
		i++;
	}
	return (count);
}

int	ft_nullstring(t_format var, int count)
{
	int k;

	k = (var.prec >= 0 && var.prec < 6 ? var.prec : 6);
	if (var.minus == 1)
	{
		count = ft_printnull(count, k);
		if (var.width > k)
			count = ft_ft_print_space(count, k, var);
	}
	else if (var.minus == 0)
	{
		if (k < var.width)
			count = ft_ft_print_space(count, k, var);
		count = ft_printnull(count, k);
	}
	return (count);
}

int	ft_printstring(t_format var, int count, va_list ap)
{
	int		k;
	char	*s;

	if (!(s = va_arg(ap, char*)))
		count = ft_nullstring(var, count);
	else if (s)
	{
		k = (var.prec >= 0 && var.prec < (int)ft_strlen(s))
			? var.prec : (int)ft_strlen(s);
		if (var.minus == 1)
		{
			count = ft_print_putstr(s, count, var);
			if (var.width > k)
				count = ft_ft_print_space(count, k, var);
		}
		else if (var.minus == 0)
		{
			if (k < var.width)
				count = ft_ft_print_space(count, k, var);
			count = ft_print_putstr(s, count, var);
		}
	}
	else
		count = ft_ft_print_space(count, 0, var);
	return (count);
}
