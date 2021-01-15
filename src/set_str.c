/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:06:56 by flohrel           #+#    #+#             */
/*   Updated: 2021/01/15 13:47:39 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		str_alloc(t_param *arg, size_t arg_len)
{
	size_t	str_len;

	if (CHK_FLAG(arg->flags, WIDTH) && (arg->width > arg_len))
		str_len = arg->width + 1;
	else if (CHK_FLAG(arg->flags, PREC))
		str_len = arg->precision + 1;
	else
		str_len = arg_len + 1;
	arg->s = malloc(sizeof(char) * str_len);
	return (str_len);
}

char	*set_str(va_list *args, t_param *arg)
{
	char	*tmp;
	size_t	arg_len;
	size_t	str_len;
	int		index;

	index = 0;
	tmp = va_arg(*args, char *);
	arg_len = ft_strlen(tmp);
	if (CHK_FLAG(arg->flags, PREC))
		arg_len = arg->precision;
	str_len = str_alloc(arg, arg_len);
	if (!arg->s)
		return (NULL);
	if (CHK_FLAG(arg->flags, WIDTH) && (arg->width > arg_len))
	{
		ft_memset(arg->s, ' ', str_len);
		if (!CHK_FLAG(arg->flags, LEFT))
			index = str_len - arg_len - 1;
	}
	ft_memcpy(arg->s + index, tmp, arg_len);
	*(arg->s + str_len - 1) = '\0';
	return (arg->s);
}
