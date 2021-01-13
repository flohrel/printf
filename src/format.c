/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:58:44 by flohrel           #+#    #+#             */
/*   Updated: 2021/01/13 16:50:18 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	g_types[9] = "cspdiuxX";
int		(*g_setf[])(va_list, t_param *) = { set_char, set_str, set_ul, set_int, set_uint, set_hex };

int		set_buffer(va_list *args, t_param *arg, const char **str)
{
	size_t	len;
	char	*s;

	if (arg->type == 1)
	{
		s = va_arg(args, (char *));
		if (CHK_FLAG(arg->flags, PREC))
			len = arg->precision + 1;
		else
			len = ft_strlen(s) + 1;
		arg->s = malloc(sizeof(char) * len);
	}
}

int		format_output(va_list *args, t_param *arg)
{
	int		type;
	int		len;
	char	*str;

	type = arg->type;
	if (type == 0)
		arg->s = g_setf[0](args, arg);
	else if (type == 1)
		arg->s = g_setf[1](args, arg);
	else if (type == 2)
		arg->s = g_setf[2](args, arg);
	else if (type == 3 || type == 4)
		arg->s = g_setf[3](args, arg);
	else if (type == 5)
		arg->s = g_setf[4](args, arg);
	else if (type == 6 || type == 7)
		arg->s = g_setf[5](args, arg);
	if (!s)
		return (ERROR);
	return (0);
}
