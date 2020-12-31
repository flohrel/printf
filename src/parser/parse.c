/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 16:56:32 by flohrel           #+#    #+#             */
/*   Updated: 2020/12/31 19:40:10 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	set_flags(t_param *arg, const char **str)
{
	while (1)
	{
		if (*str == '-')
			SET_FLAG(arg->flags, LEFT);
		else if (*str == '0')
			SET_FLAG(arg->flags, ZERO);
		else if (*str == '.')
			SET_FLAG(arg->flags, PREC);
		else if (*str == '*')
			SET_FLAG(arg->flags, WIDTH);
		else
			break ;
		str++;
	}
}

int		set_type(t_param *arg, const char *str)
{
	
}

int		parse_param(t_param *arg, const char *str)
{
	set_flags(&arg, &str);
	if (set_type(&arg, &str))
		return (ERROR);
}
