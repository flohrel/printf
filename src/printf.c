/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 04:39:21 by flohrel           #+#    #+#             */
/*   Updated: 2020/12/30 21:20:04 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const char *str, ...)
{
	t_param	arg;
	va_list	args;

	va_start(args, str);
	while (*str)
	{
		if (*str != '%' || (*(++str) == '%'))
			display(*str);
		else
		{
			init_param(&arg);				// parameter struct init
			if (!get_flags(&(arg.flags), &str))	// get flags and increment *str
				return (-1);
			if (!get_format(&(arg.type)))
				return (-1);
		}
		str++;
	}
}
