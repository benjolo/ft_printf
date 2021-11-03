/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalaria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:45:39 by bvalaria          #+#    #+#             */
/*   Updated: 2021/01/28 17:45:45 by bvalaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_format	ft_init_prec(t_format var, const char *s, va_list ap)
{
	var.prec = 0;
	var.i += 1;
	if (s[var.i] == '-' && ft_isdigit(s[var.i + 1]))
	{
		var.minus = 1;
		var.i++;
		while (ft_isdigit(s[var.i]))
			var.prec = var.prec * 10 + ((int)s[var.i++] - 48);
	}
	if (s[var.i] == '*')
	{
		var.prec = va_arg(ap, int);
		if (var.prec < 0)
			var.prec = -1;
		var.i += 1;
	}
	if (ft_isdigit(s[var.i]))
	{
		while (ft_isdigit(s[var.i]))
			var.prec = var.prec * 10 + ((int)s[var.i++] - 48);
	}
	return (var);
}

t_format	ft_init_var(t_format var, const char *s, va_list ap)
{
	while (s[var.i] == '-' || s[var.i] == '0')
	{
		if (s[var.i] == '-')
			var.minus = 1;
		if (s[var.i] == '0')
			var.zero = 1;
		var.i++;
	}
	if (s[var.i] == '*')
	{
		var.width = va_arg(ap, int);
		if (var.width < 0)
		{
			var.minus = 1;
			var.width = -var.width;
		}
		var.i++;
	}
	else if (ft_isdigit(s[var.i]))
		while (ft_isdigit(s[var.i]))
			var.width = var.width * 10 + ((int)s[var.i++] - 48);
	if (s[var.i] == '.')
		var = ft_init_prec(var, s, ap);
	var.type = s[var.i];
	return (var);
}

int			ft_stampa(const char *s, int i, int count, va_list ap)
{
	t_format	var;

	var.minus = 0;
	var.zero = 0;
	var.width = 0;
	var.prec = -1;
	var.type = 0;
	var.i = i + 1;
	var = ft_init_var(var, s, ap);
	if (var.type == 'c')
		count = ft_printchar(var, count, ap);
	if (var.type == 'd' || var.type == 'i')
		count = ft_printinteger(var, count, ap);
	if (var.type == 'u')
		count = ft_printu(var, count, ap);
	if (var.type == 's')
		count = ft_printstring(var, count, ap);
	if (var.type == 'x' || var.type == 'X')
		count = ft_printhex(var, count, ap);
	if (var.type == 'p')
		count = ft_printpointer(var, count, ap);
	if (var.type == '%')
		count = ft_printpercent(var, count);
	return (count);
}

int			ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	ap;

	i = 0;
	count = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%' && ft_checkformat(s, i))
		{
			count = ft_stampa(s, i, count, ap);
			i = ft_checkformat(s, i);
		}
		else if (!s[i])
			break ;
		else
		{
			count = ft_print_c(s[i], count);
			i++;
		}
	}
	va_end(ap);
	return (count);
}
