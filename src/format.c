/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:58:44 by flohrel           #+#    #+#             */
/*   Updated: 2021/01/15 18:52:22 by flohrel          ###   ########.fr       */
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

char	*n_str_format()
{
}

char	*ft_itoa_base(unsigned long nb, char *base, int bt_size, int is_neg)
{
	char		*nb_str;

	g_size++;
	if (nb >= (unsigned int)bt_size)
		n = ft_itoa_base(nb / bt_size, base, bt_size, is_neg);
	else
	{
		if (is_neg)
		{
			if (!(n = (char *)malloc(sizeof(char) * (g_size += 2))))
				return (NULL);
			n[g_idx++] = '-';
		}
		else if (!(n = (char *)malloc(sizeof(char) * (g_size += 1))))
			return (NULL);
		n[g_size - 1] = '\0';
	}
	n[g_idx++] = base[nb % bt_size];
	return (n);
}

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
