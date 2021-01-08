/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 04:39:21 by flohrel           #+#    #+#             */
/*   Updated: 2021/01/01 19:23:07 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	init_param(t_param *arg)
{
	arg->type = 0;
	arg->flags = 0;
	arg->width = 0;
	arg->precision = 0;
	arg->s = NULL;
}

int		ft_printf(const char *str, ...)
{
	t_param	arg;
	va_list	args;
	size_t	count;

	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%' && (*(++str) != '%'))
		{
			init_param(&arg);
			if (parse_param(&arg, &str) ||
				format_output(&arg))		// malloc arg.s + set arg.s
				return (ERROR);
			count += out(s, sizeof(char *));
			free(arg.s);
		}
		else
			count += out(*str, sizeof(char));
		str++;
	}
	return (count);
}
