/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:58:44 by flohrel           #+#    #+#             */
/*   Updated: 2021/01/16 19:40:46 by flohrel          ###   ########.fr       */
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

/*char	*ft_itoa_base(unsigned long nb, char *base, size_t base_len, t_bool is_negative)
{
	char			*nb_str;
	static size_t	nb_len = 0;
	static size_t	index = 0;

	nb_len++;
	if (nb >= base_len)
		n = ft_itoa_base(nb / base_len, base, base_len, is_negative);
	else
	{
		index = 0;
		if (is_neg)
		{
			nb_str = ft_calloc(nb_len += 2, sizeof(char));
			if (n)
				nb_str[index++] = '-';
		}
		else
			nb_str = ft_calloc(nb_len += 1, sizeof(char));
		if (!n)
			return (NULL);
		nb_str[nb_len - 1] = '\0';
	}
	nb_str[index++] = base[nb % bt_size];
	nb_len--;
	return (n);
}*/

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
