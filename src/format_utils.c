/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:23:53 by flohrel           #+#    #+#             */
/*   Updated: 2021/01/27 14:53:47 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	set_int(va_list *args, t_param *arg)
{
	long		nb;
	char		*tmp;
	int			index;
	int			tmp_len;
	t_bool		is_neg;

	is_neg = FALSE;
	nb = va_arg(*args, int);
	index = 0;
	if (nb < 0)
	{
		is_neg = TRUE;
		index = 1;
		nb = -nb;
	}
	if (!(tmp = ft_ltoa(nb)) ||
		(tmp_len = number_format(arg, &tmp, ft_strlen(tmp))) == -1)
		return ;
	if (CHK_FLAG(arg->flags, WIDTH) && (arg->width > tmp_len) &&
		!CHK_FLAG(arg->flags, LEFT))
		index = arg->width - tmp_len;
	ft_memcpy(arg->buffer + index, tmp, tmp_len);
	if (is_neg || CHK_FLAG(arg->flags, SIGN))
		set_sign(arg, index, is_neg);
	free(tmp);
}

void	set_uint(va_list *args, t_param *arg)
{
	unsigned int	nb;
	int				tmp_len;
	size_t			index;
	char			*tmp;

	nb = (unsigned int)va_arg(*args, int);
	tmp = ft_ltoa(nb);
	if (!tmp)
		return ;
	tmp_len = number_format(arg, &tmp, ft_strlen(tmp));
	if (tmp_len == -1)
		return ;
	index = 0;
	if (CHK_FLAG(arg->flags, WIDTH) && (arg->width > tmp_len) &&
		!CHK_FLAG(arg->flags, LEFT))
		index = arg->width - tmp_len;
	ft_memcpy(arg->buffer + index, tmp, tmp_len);
	free(tmp);
}

void	set_ptr(va_list *args, t_param *arg)
{
	unsigned long	ptr_addr;
	char			*tmp;
	int				tmp_len;
	size_t			index;

	ptr_addr = (unsigned long)va_arg(*args, void *);
	tmp = ft_ultoa_base(ptr_addr, "0123456789abcdef");
	if (!tmp)
		return ;
	tmp_len = number_format(arg, &tmp, ft_strlen(tmp));
	if (tmp_len == -1)
		return ;
	index = 2;
	if (CHK_FLAG(arg->flags, WIDTH) && (arg->width > tmp_len + 2) &&
		!CHK_FLAG(arg->flags, LEFT))
		index = arg->width - tmp_len;
	ft_memcpy(arg->buffer + index, tmp, tmp_len);
	ft_memcpy(arg->buffer + (index - 2), "0x", 2);
	if (tmp)
		free(tmp);
}

void	set_str(va_list *args, t_param *arg)
{
	char	*str;
	int		str_len;
	size_t	index;

	str = va_arg(*args, char *);
	str_len = 0;
	if (str)
		str_len = ft_strlen(str);
	else
		str_len = 6;
	if (CHK_FLAG(arg->flags, PREC) && (arg->precision < str_len))
		str_len = arg->precision;
	index = 0;
	if (!CHK_FLAG(arg->flags, LEFT) && CHK_FLAG(arg->flags, WIDTH) &&
		(arg->width > str_len))
		index = arg->width - str_len;
	if (str)
		ft_memcpy(arg->buffer + index, str, str_len);
	else
		ft_memcpy(arg->buffer + index, NULLSTR, str_len);
}

void	set_char(va_list *args, t_param *arg)
{
	unsigned char	c;

	c = (unsigned char)va_arg(*args, int);
	if (!arg->width)
		arg->width++;
	if (CHK_FLAG(arg->flags, LEFT))
		*(arg->buffer) = c;
	else
		*(arg->buffer + arg->width - 1) = c;
}
