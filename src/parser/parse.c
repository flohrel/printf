/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 16:56:32 by flohrel           #+#    #+#             */
/*   Updated: 2021/01/03 20:59:39 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	set_size(t_param *arg, const char **str)
{
	while (1)
	{
		if (ft_isdigit(**str) || (**str == '.'))
		{
			if (**str == '.')
			{
				SET_FLAG(arg->flags, PREC);
				size = arg->precision;
				str++;
			}
			else
			{
				SET_FLAG(arg->flags, WIDTH);
				size = arg->width;
			}
			size = ft_atoi(*str);
			while (ft_isdigit(**str))
				*str++;
		}
	}
}

void	set_flags(t_param *arg, const char **str)
{
	while (1)
	{
		if (**str == '-')
			SET_FLAG(arg->flags, LEFT);
		else if (**str == '0' && !CHK_FLAG(arg->flags, LEFT))
			SET_FLAG(arg->flags, ZERO);
		else
			break ;
		*str++;
	}
}

int		set_type(t_param *arg, const char *str)
{
	
}

int		parse_param(t_param *arg, const char *str)
{
	set_flags(&arg, &str);
	set_width(&arg, &str);
	if (set_type(&arg, &str))
		return (ERROR);
}
