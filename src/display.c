/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:49:41 by flohrel           #+#    #+#             */
/*   Updated: 2021/01/26 13:30:42 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_out(t_param *arg)
{
	if (arg->type == 0)
		return (write(STDOUT_FILENO, arg->buffer, arg->width));
	else
		return (ft_putstr_fd(arg->buffer, STDOUT_FILENO));
}