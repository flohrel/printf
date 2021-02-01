/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 04:39:21 by flohrel           #+#    #+#             */
/*   Updated: 2021/01/30 12:42:46 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_struct(t_param *arg)
{
	arg->type = -1;
	arg->flags = 0;
	arg->width = 0;
	arg->precision = 0;
	ft_bzero(arg->buffer, BUF_SIZE);
}

int		ft_printf(const char *str, ...)
{
	t_param	arg;
	va_list	args;
	int		count;

	count = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if ((*str == '%') && (++str))
		{
			init_struct(&arg);
			if (parse_param(&args, &arg, &str) == ERROR)
				return (ERROR);
			if (arg.type == 9)
				set_count(&args, count);
			else if (format_output(&args, &arg) == ERROR)
				return (ERROR);
			count += print_out(&arg);
		}
		else if (++count)
			ft_putchar_fd(*str, STDOUT_FILENO);
		str++;
	}
	va_end(args);
	return (count);
}
