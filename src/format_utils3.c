/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:41:42 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/01 01:05:39 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	(*g_ftoa[])(t_param *, float) = { set_f }; //, set_g, set_e };

char	*set_f(t_param *arg, float f)
{
	char	*ipart;
	char	*str;
	int		prec;

	ipart = ft_itoa((int)f);
	f -= (int)f;
	printf("f=%f - ipart=%s\n", f, ipart);
}

void	set_float(va_list *args, t_param *arg)
{
	float	f;
	char	*tmp;
	int		index;
	int		tmp_len;
	t_bool	is_neg;

	is_neg = FALSE;
	f = va_arg(args, float);
	index = 0;
	if ((f < 0) || check_flag(arg->flags, SIGN) || check_flag(arg->flags, BLANK))
	{
		if ((f < 0) && (is_neg = TRUE))
			f = -f;
		index = 1;
	}
	if (!(tmp = g_ftoa[arg->type - 9](arg, f)) ||
		(tmp_len = number_format(arg, &tmp, ft_strlen(tmp))) == -1)
		return ;
	if (check_flag(arg->flags, WIDTH) && (arg->width > tmp_len) &&
		!check_flag(arg->flags, LEFT))
		index = arg->width - tmp_len;
	ft_memcpy(arg->buffer + index, tmp, tmp_len);
	if (is_neg || check_flag(arg->flags, SIGN) || check_flag(arg->flags, BLANK))
		set_sign(arg, index, is_neg);
	free(tmp);
}
