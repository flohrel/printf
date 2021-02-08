/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 16:56:32 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/08 14:38:28 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	g_types[13] = "cspudixX%nfge";

int		set_flags(va_list *args, t_param *arg, const char **str)
{
	char	c;

	c = **str;
	if (c == '-')
		set_flag(&arg->flags, LEFT);
	else if (c == '0')
		set_flag(&arg->flags, ZERO);
	else if (c == ' ')
		set_flag(&arg->flags, BLANK);
	else if (c == '+')
		set_flag(&arg->flags, SIGN);
	else if (c == '#')
		set_flag(&arg->flags, ALT);
	else if (c == '.')
		set_precision(args, arg, str);
	else if (ft_isdigit(c) || c == '*')
		set_width(args, arg, str);
	else if (ft_strchr("hl", c))
		set_lenmod(arg, str);
	else
		return (0);
	(*str)++;
	return (1);
}

int		set_type(const char **str)
{
	int		i;
	char	c;

	i = -1;
	c = **str;
	while (g_types[++i])
		if (c == g_types[i])
			return (i);
	return (ERROR);
}

int		parse_param(va_list *args, t_param *arg, const char **str)
{
	while (set_flags(args, arg, str))
		;
	arg->type = set_type(str);
	if (arg->type == -1)
		return (ERROR);
	return (0);
}
