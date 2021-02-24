/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:34:32 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/15 16:23:06 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	(*str)--;
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
	(*str)--;
}

void	set_lenmod(t_param *arg, const char **str)
{
	if (**str == 'h')
	{
		if (*((*str) + 1) == 'h')
		{
			set_flag(&arg->flags, LMOD_HH);
			(*str)++;
		}
		else
			set_flag(&arg->flags, LMOD_H);
	}
	else
	{
		if (*((*str) + 1) == 'l')
		{
			set_flag(&arg->flags, LMOD_LL);
			(*str)++;
		}
		else
			set_flag(&arg->flags, LMOD_L);
	}
}
