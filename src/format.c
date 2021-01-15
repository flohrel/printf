/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:58:44 by flohrel           #+#    #+#             */
/*   Updated: 2021/01/15 13:23:48 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*(*g_setf[])(va_list *, t_param *) = { set_char, set_str, set_ul, set_int, set_uint, set_hex };

int		format_output(va_list *args, t_param *arg)
{
	int		type;
//	int		len;
//	char	*str;

	type = arg->type;
	if (type == 4 || type == 5)
		arg->s = g_setf[4](args, arg);
	else if (type == 6 || type == 7)
		arg->s = g_setf[5](args, arg);
	else
		arg->s = g_setf[type](args, arg);
	if (!arg->s)
		return (ERROR);
//	printf("type=%-5d\tflags=%-5d\twidth=%-5lu\tprecision=%-5lu\n", arg->type, arg->flags, arg->width, arg->precision);
	printf("%s\n", arg->s);
	return (0);
}
