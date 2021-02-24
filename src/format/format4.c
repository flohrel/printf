/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 02:00:07 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/19 11:11:23 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	round_float(t_float *f)
{
	long	l;

	l = (long)(f->nb * 10);
	if ((l % 10) >= 5 && (f->afterpoint != 6))
		l = (l / 10) + 1;
	else
		l /= 10;
	return (l);
}

int		init_float_struct(t_float *f, t_param *arg)
{
	int		i;

	f->afterpoint = 6;
	if (check_flag(arg->flags, PREC))
		f->afterpoint = arg->precision;
	f->is_neg = FALSE;
	if ((f->nb < 0) && (f->is_neg = TRUE))
		f->nb = -(f->nb);
	f->index = 0;
	if (check_flag(arg->flags, BLANK + SIGN) || f->is_neg)
		f->index++;
	f->integer = (long)f->nb;
	f->nb -= f->integer;
	i = -1;
	while (++i < f->afterpoint)
		f->nb *= 10;
	f->fractional = round_float(f);
	f->int_s = ft_ltoa(f->integer);
	f->frac_s = ft_ltoa(f->fractional);
	if (!f->int_s || !f->frac_s)
		return (-1);
	return (0);
}

void	set_float(va_list *args, t_param *arg)
{
	t_float	f;
	int		int_len;
	int		frac_len;

	f.nb = va_arg(*args, double);
	if (init_float_struct(&f, arg) == -1)
		return ;
	int_len = ft_strlen(f.int_s);
	frac_len = ft_strlen(f.frac_s);
	f.tmp_len = int_len;
	if (f.afterpoint)
		f.tmp_len += frac_len + 1;
	if (check_flag(arg->flags, WIDTH) && (arg->width > f.tmp_len) &&
		!check_flag(arg->flags, LEFT))
		f.index = arg->width - f.tmp_len;
	ft_memcpy(arg->buffer + f.index, f.int_s, int_len);
	if (f.afterpoint)
	{
		ft_memcpy(arg->buffer + f.index + int_len, ".", 1);
		ft_memcpy(arg->buffer + f.index + int_len + 1, f.frac_s, frac_len);
	}
	if (f.is_neg || check_flag(arg->flags, BLANK + SIGN))
		set_sign(arg, f.index, f.is_neg);
	free(f.int_s);
	free(f.frac_s);
}
