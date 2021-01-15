/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:58:44 by flohrel           #+#    #+#             */
/*   Updated: 2021/01/15 18:29:46 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*(*g_setf[])(va_list *, t_param *) = { set_char, set_str, set_ul, set_int, set_uint, set_hex };

char	*n_str_alloc(t_param *arg, size_t nb_len)
{
	size_t	str_len;
	char	*nb_str;

	str_len = nb_len;
	if (CHK_FLAG(arg->flags, PREC) && (arg->precision > nb_len))
		str_len = arg->precision;
	if (CHK_FLAG(arg->flags, WIDTH) && (arg->width > str_len))
		str_len = arg->width;
	nb_str = malloc(sizeof(char) * (str_len + 1));
	if (!nb_str)
		return (NULL);
	nb_str[str_len] = '\0';
	return (nb_str);
}

char	*itoa_base(long n, char *base, t_bool is_negative)
{
	
}

/*void	n_*/

int		format_output(va_list *args, t_param *arg)
{
	int		type;

	type = arg->type;
	if (type == 4 || type == 5)
		arg->s = g_setf[4](args, arg);
	else if (type == 6 || type == 7)
		arg->s = g_setf[5](args, arg);
	else
		arg->s = g_setf[type](args, arg);
	if (!arg->s)
		return (ERROR);
	return (0);
}
