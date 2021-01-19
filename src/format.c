/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:58:44 by flohrel           #+#    #+#             */
/*   Updated: 2021/01/19 16:44:25 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*(*g_setf[])(va_list *, t_param *) = {
	set_char, set_str, set_ul, set_int, set_uint, set_hex };

size_t	n_str_alloc(t_param *arg, char **nb_str, size_t nb_len)
{
	size_t	str_len;
	char	c;

	c = 0;
	str_len = nb_len;
	if (CHK_FLAG(arg->flags, PREC) && (arg->precision > str_len))
		str_len = arg->precision;
	if (CHK_FLAG(arg->flags, WIDTH) && (arg->width > str_len))
	{
		if (CHK_FLAG(arg->flags, ZERO) && !(CHK_FLAG(arg->flags, LEFT)))
			c = '0';
		else
			c = ' ';
		str_len = arg->width;
	}
	*nb_str = ft_calloc(str_len + 1, sizeof(char));
	if (!nb_str)
		return (-1);
	if (c)
		ft_memset(*nb_str, c, str_len);
	*((*nb_str) + str_len) = '\0';
	return (str_len);
}

size_t	number_format(t_param *arg, char **tmp, size_t tmp_len)
{
	char	*nb_str;

	if (CHK_FLAG(arg->flags, PREC) && (arg->precision > tmp_len))
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
	return (tmp_len);
}

int		format_output(va_list *args, t_param *arg)
{
	int		type;

	type = arg->type;
	if (type == 4 || type == 5)
		arg->s = g_setf[4](args, arg);
	else if (type == 6 || type == 7)
		arg->s = g_setf[5](args, arg);
	else
		arg->s = g_setf[type](args, arg);
	if (!arg->s)
		return (ERROR);
	return (0);
}
