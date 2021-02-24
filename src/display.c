/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:49:41 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/19 10:44:18 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_out(t_param *arg)
{
	if (arg->type == 0 && !check_flag(arg->flags, LMOD_L))
		return (write(STDOUT_FILENO, arg->buffer, arg->width));
	else
		return (ft_putstr_fd(arg->buffer, STDOUT_FILENO));
}
