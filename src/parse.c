/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 16:56:32 by flohrel           #+#    #+#             */
/*   Updated: 2021/01/31 19:41:01 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	g_types[13] = "cspudixX%fgen";

void	set_precision(va_list *args, t_param *arg, const char **str)
{
	int	size;

	(*str)++;
	set_flag(&arg->flags, PREC);
	if (**str == '*')
	{
		size = va_arg(*args, int);
		(*str)++;
	}
	else
	{
		size = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
	}
	if (size >= 0)
		arg->precision = size;
	else
	{
		clear_flag(&arg->flags, PREC);
		arg->precision = 0;
	}
}

void	set_width(va_list *args, t_param *arg, const char **str)
{
	int	size;

	set_flag(&arg->flags, WIDTH);
	if (**str == '*')
	{
		size = va_arg(*args, int);
		(*str)++;
	}
	else
	{
		size = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
	}
	if (size >= 0)
		arg->width = size;
	else
	{
		set_flag(&arg->flags, LEFT);
		arg->width = -size;
	}
}

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
	else if (c == '.' || ft_isdigit(c) || c == '*')
	{
		if (c == '.')
			set_precision(args, arg, str);
		else
			set_width(args, arg, str);
		return (1);
	}
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
