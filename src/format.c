/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:58:44 by flohrel           #+#    #+#             */
/*   Updated: 2021/01/21 11:13:56 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*(*g_setf[])(va_list *, t_param *) = {
	set_char, set_str, set_ul, set_uint, set_int, set_hex };

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
		c = ' ';
		str_len = arg->width;
		if (CHK_FLAG(arg->flags, ZERO) && !(CHK_FLAG(arg->flags, LEFT)) &&
			!CHK_FLAG(arg->flags, PREC))
			c = '0';
	}
	*nb_str = ft_calloc(str_len + 1, sizeof(char));
	if (!nb_str)
		return (-1);
	if (c)
		ft_memset(*nb_str, c, str_len);
	*((*nb_str) + str_len) = '\0';
	return (str_len);
}

size_t	number_format(t_param *arg, char **nb_str, size_t nb_len)
{
	char	*tmp;

	if (CHK_FLAG(arg->flags, PREC))
	{
		if (arg->precision > nb_len)
		{
			tmp = ft_calloc(arg->precision, sizeof(char));
			if (!tmp)
				return (-1);
			ft_memset(tmp, '0', arg->precision);
			ft_memcpy(tmp + (arg->precision - nb_len), *nb_str, nb_len);
			free(*nb_str);
			*nb_str = tmp;
			return (arg->precision);
		}
		if (!arg->precision && (nb_len == 1) && (**nb_str == '0'))
		{
			*nb_str = NULL;
			return (0);
		}
	}
	return (nb_len);
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

// printf("type=%d flags=%d width=%d precision=%d string=%s\n", arg->type, arg->flags, arg->width, arg->precision, arg->s);
