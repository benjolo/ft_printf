/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalaria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:45:40 by bvalaria          #+#    #+#             */
/*   Updated: 2021/01/26 15:45:46 by bvalaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_getorder(int nb)
{
	int	order;
	int i;
	int n;

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

int		ft_intprec(int prec, int len, int n, int count)
{
	int i;
	int size;

	i = prec;
	size = len;
	if (n < 0)
	{
		write(1, "-", 1);
		if (n == -2147483648)
			count++;
	}
	while (i > size)
	{
		count = ft_print_c('0', count);
		i--;
	}
	return (count);
}

int		ft_intwidth(int width, int len, int prec, int count)
{
	int i;
	int lim;

	i = width;
	lim = prec;
	if (lim < len)
		lim = len;
	while (i > lim)
	{
		count = ft_print_c(' ', count);
		i--;
	}
	return (count);
}

int		ft_iscinstr(char c, char const *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
