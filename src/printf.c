/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 04:39:21 by flohrel           #+#    #+#             */
/*   Updated: 2021/01/20 14:31:12 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	init_param(t_param *arg)
{
	arg->type = -1;
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
	while (*str != '\0')
	{
		if (*str == '%' && (*(++str) != '%'))
		{
			init_param(&arg);
			if (parse_param(&args, &arg, &str) == ERROR)
				return (ERROR);
			if (format_output(&args, &arg) == ERROR)
				return (ERROR);
			count += ft_putstr_fd(arg.s, STDOUT_FILENO);
			free(arg.s);
		}
		else if (++count)
			ft_putchar_fd(*str, STDOUT_FILENO);
		str++;
	}
	va_end(args);
	return (count);
}
