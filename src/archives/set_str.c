/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:06:56 by flohrel           #+#    #+#             */
/*   Updated: 2021/01/20 16:15:19 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		str_alloc(t_param *arg, size_t *arg_len, char **tmp)
{
	size_t	str_len;

	if (CHK_FLAG(arg->flags, PREC) && (arg->precision < *arg_len))
		*arg_len = arg->precision;
	if (CHK_FLAG(arg->flags, WIDTH) && (arg->width > *arg_len))
		str_len = arg->width + 1;
	else
		str_len = *arg_len + 1;
	*tmp = ft_calloc(str_len, sizeof(char));
	return (str_len);
}

char	*set_str(va_list *args, t_param *arg)
{
	char	*tmp;
	char	*str;
	char	*null_str;
	size_t	arg_len;
	size_t	str_len;

	null_str = ft_strdup("(null)");
	tmp = va_arg(*args, char *);
	if (!tmp)
		tmp = null_str;
	arg_len = ft_strlen(tmp);
	str_len = str_alloc(arg, &arg_len, &str);
	if (!str)
		return (NULL);
	ft_memset(str, ' ', str_len);
	if (CHK_FLAG(arg->flags, PREC) && (arg->precision < arg_len))
		arg_len = arg->precision;
	if (!CHK_FLAG(arg->flags, LEFT))
		ft_memcpy(str + (str_len - arg_len - 1), tmp, arg_len);
	else
		ft_memcpy(str, tmp, arg_len);
	*(str + str_len - 1) = '\0';
	free(null_str);
	return (str);
}
