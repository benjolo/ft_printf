/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalaria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 12:44:28 by bvalaria          #+#    #+#             */
/*   Updated: 2021/01/29 12:44:50 by bvalaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_zeroperc(t_format var, int count)
{
	if (var.zero == 1)
	{
		if (var.prec < 1)
			var.prec = 1;
		while (var.width > var.prec)
		{
			count = ft_print_c('0', count);
			var.width--;
		}
	}
	else
		count = ft_print_sp(var.width, count);
	count = ft_print_c('%', count);
	return (count);
}

int	ft_printpercent(t_format var, int count)
{
	char	c;

	c = '%';
	if (var.width > 0)
	{
		if (var.minus == 1)
		{
			count = ft_print_c(c, count);
			count = ft_print_sp(var.width, count);
		}
		else
			count = ft_zeroperc(var, count);
	}
	else
		count = ft_print_c(c, count);
	return (count);
}

int	ft_checkprec(const char *s, int k)
{
	if (s[k] == '*' || ft_isdigit(s[k]) || s[k] == '-')
	{
		if (s[k] == '*')
			k++;
		else if (s[k] == '-' && (ft_isdigit(s[k + 1])))
		{
			k++;
			while (ft_isdigit(s[k]))
				k++;
		}
		else if (ft_isdigit(s[k]))
			while (ft_isdigit(s[k]))
				k++;
	}
	return (k);
}

int	ft_checkformat(const char *s, int i)
{
	int		k;

	k = i + 1;
	while (s[k] == '-' || s[k] == '0')
		k++;
	if (s[k] == '*' || ft_isdigit(s[k]))
	{
		if (s[k] == '*')
			k++;
		else
			while (ft_isdigit(s[k]))
				k++;
	}
	if (s[k] == '.')
	{
		k++;
		k = ft_checkprec(s, k);
	}
	return ((ft_iscinstr(s[k], "cspdiuxX%") ? k + 1 : 0));
}
