/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalaria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:16:09 by bvalaria          #+#    #+#             */
/*   Updated: 2021/01/22 12:04:49 by bvalaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_format
{
	int		minus;
	int		zero;
	int		width;
	int		prec;
	int		i;
	char	type;
}					t_format;

int					ft_printf(const char *s, ...);
int					ft_stampa(const char *s, int i, int count, va_list ap);
t_format			ft_init_var(t_format var, const char *s, va_list ap);
t_format			ft_init_prec(t_format var, const char *s, va_list ap);
int					ft_checkformat(const char *s, int i);
int					ft_checkprec(const char *s, int k);
int					ft_iscinstr(char c, char const *str);
int					ft_printstring(t_format var, int count, va_list ap);
int					ft_nullstring(t_format var, int count);
int					ft_ft_print_space(int count, int k, t_format var);
int					ft_print_putstr(char *str, int count, t_format var);
int					ft_printhex(t_format var, int count, va_list ap);
int					ft_secondprinthex(t_format var, int count, int len,
					unsigned int n);
int					ft_puthexnbr(unsigned int n, int count, int len,
					t_format var);
void				ft_hexstring(char *s, t_format var);
int					ft_count(unsigned int n);
int					ft_printu(t_format var, int count, va_list ap);
int					ft_putunsignednbr(unsigned int nb, int count, t_format var);
int					ft_unsintprec(int prec, int len, int count);
int					ft_unsgetorder(unsigned int nb);
int					ft_printinteger(t_format var, int count, va_list ap);
int					ft_minmaxint(int n, t_format var, int count);
int					ft_putnbr(int nb, int count, t_format var);
int					ft_rightputnbr(int nb, int count);
int					ft_intwidth(int width, int len, int prec, int count);
int					ft_intprec(int prec, int len, int n, int count);
int					ft_getorder(int nb);
int					ft_printchar(t_format var, int count, va_list ap);
int					ft_print_c(char c, int count);
int					ft_isdigit(int c);
void				ft_putchar(char c);
size_t				ft_strlen(const char *str);
int					ft_printpercent(t_format var, int count);
int					ft_zeroperc(t_format var, int count);
int					ft_print_sp(int n, int count);
int					ft_print_c(char c, int count);
int					ft_printnull(int count, int k);
void				ft_string(char *s, t_format var);
int					ft_discount(size_t n);
int					ft_pointprec(t_format var, int len, int n, int count);
int					ft_putpointer(size_t n, int count, int len, t_format var);
int					ft_printpointer(t_format var, int count, va_list ap);
int					ft_secondprintpointer(t_format var, int count, int len,
					size_t n);

#endif
