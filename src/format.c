/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:58:44 by flohrel           #+#    #+#             */
/*   Updated: 2021/01/26 13:39:01 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	(*g_setf[])(va_list *, t_param *) = {
	set_char, set_str, set_ptr, set_uint, set_int, set_int, set_hex, set_hex, \
	set_notype };

int		number_format(t_param *arg, char **tmp, int tmp_len)
{
	char	*nb_str;

	if (CHK_FLAG(arg->flags, PREC))
	{
		if (arg->precision > tmp_len)
		{
			nb_str = ft_calloc(arg->precision, sizeof(char));
			if (!nb_str)
				return (-1);
			ft_memset(nb_str, '0', arg->precision);
			ft_memcpy(nb_str + (arg->precision - tmp_len), *tmp, tmp_len);
			free(*tmp);
			*tmp = nb_str;
			return (arg->precision);
		}
		if (!arg->precision && (tmp_len == 1) && (**tmp == '0'))
		{
			free(*tmp);
			*tmp = NULL;
			return (0);
		}
	}
	return (tmp_len);
}

void	init_string(t_param *arg)
{
	char	c;

	c = 0;
	if (CHK_FLAG(arg->flags, WIDTH))
	{
		c = ' ';
		if (CHK_FLAG(arg->flags, ZERO) && !(CHK_FLAG(arg->flags, LEFT)) &&
			!CHK_FLAG(arg->flags, PREC))
			c = '0';
	}
	if (c)
		ft_memset(arg->buffer, c, arg->width);
}

int		format_output(va_list *args, t_param *arg)
{
	init_string(arg);
	g_setf[arg->type](args, arg);
	return (0);
}
