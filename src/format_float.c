/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 02:27:09 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/04 17:21:30 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
void	(*g_float_fun[])(va_list *, t_param *) = {
	f_type }; // g_type, e_type };

typedef union	u_float
{
	double	flt;
	char	data[sizeof(double)];
}				t_float;

double	ft_power(double f, int exp, int base)
{
	while (exp--)
		f *= base;
	return (f);
}

/*void	init_float(t_float *f, va_list *args)
{
//	long		i;
//	int		precision;

	if (f < 0)
	{
		flt->is_neg = TRUE;
		f = -f;
	}
	i = (long)f;
	if (i == 0)
		flt->neg_exp = TRUE;
	else
		flt->neg_exp = FALSE;
	flt->integer = i;
	f -= i;
//	precision = 6;
//	if (check_flag(arg->flags, PREC))
//		precision = arg->precision;
}*/

void	f_type(va_list *args, t_param *arg)
{
	t_float	f;
//	t_float	flt;
//	char	*f_str;
//	char	*i_str;
//	long	i;

	(void)arg;
	f.flt = va_arg(*args, double);
	printf("f->flt = %f\n", f.flt);
	printf("64-bit double: sign: %d\n", (f.data[0] & 0x80) >> 7);
//	i_str = ft_ltoa(flt->integer);
}

void	set_float(va_list *args, t_param *arg)
{
	(void)arg;
	g_float_fun[arg->type - 10](args, arg);
}
