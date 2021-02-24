/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenmod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:57:27 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/19 11:32:33 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	unsigned_lenmod(va_list *args, t_param *arg)
{
	t_type	var;

	if (check_flag(arg->flags, LMOD_H))
		return (var.us = (unsigned short)va_arg(*args, int));
	else if (check_flag(arg->flags, LMOD_HH))
		return (var.uc = (unsigned char)va_arg(*args, int));
	else if (check_flag(arg->flags, LMOD_L))
		return (var.ul = va_arg(*args, unsigned long));
	else if (check_flag(arg->flags, LMOD_LL))
		return (var.ull = va_arg(*args, unsigned long long));
	else
		return (var.ui = va_arg(*args, unsigned int));
}

long long			signed_lenmod(va_list *args, t_param *arg)
{
	t_type	var;

	if (check_flag(arg->flags, LMOD_H))
		return (var.si = (short)va_arg(*args, int));
	else if (check_flag(arg->flags, LMOD_HH))
		return (var.c = (char)va_arg(*args, int));
	else if (check_flag(arg->flags, LMOD_L))
		return (var.l = va_arg(*args, long));
	else if (check_flag(arg->flags, LMOD_LL))
		return (var.ll = va_arg(*args, long long));
	else
		return (var.i = va_arg(*args, int));
}
