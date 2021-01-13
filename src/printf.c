/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 04:39:21 by flohrel           #+#    #+#             */
/*   Updated: 2021/01/13 16:57:20 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	init_param(t_param *arg)
{
	arg->type = -1;
	arg->flags = 0;
	arg->width = 0;
	arg->precision = 0;
	arg->str = NULL;
}

int		ft_printf(const char *str, ...)
{
	t_param	arg;
	va_list	args;
	size_t	count;

	va_start(args, str);
	count = 0;
	while (*str != '\0')
	{
		if (*str == '%' && (*(++str) != '%'))
		{
			init_param(&arg);
			if (parse_param(&args, &arg, &str) == ERROR)
				return (ERROR);
			if (format_output(&args, &arg, &str) == ERROR)
				return (ERROR);				// FUNCTION POINTER w/ arg->type + malloc arg.s + set arg.s
//			count += out(s, sizeof(char *));
			free(arg.s);
			printf("type=%-5d\tflags=%-5d\twidth=%-5lu\tprecision=%-5lu\n", arg.type, arg.flags, arg.width, arg.precision);
		}
//		else
//			count += out(*str, sizeof(char));
		str++;
	}
	va_end(args);
	return (count);
}
