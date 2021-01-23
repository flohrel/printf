/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:58:44 by flohrel           #+#    #+#             */
/*   Updated: 2021/01/23 13:57:01 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	(*g_setf[])(va_list *, t_param *) = {
	set_char, set_str, set_ptr }; // set_uint, set_int, set_int, set_hex, set_hex, set_notype };

void	set_ptr(va_list *args, t_param *arg)
{
	unsigned long	ptr_addr;
	char			*tmp_str;
	size_t			tmp_len;
	size_t			index;
	
	ptr_addr = (unsigned long)va_arg(*args, void *);
	tmp_str = ft_ultoa_base(ptr_addr, "0123456789abcdef");
	if (!tmp_str)
		return ;
	tmp_len = ft_strlen(tmp_str);
	index = 2;
	if (!CHK_FLAG(arg->flags, LEFT) && CHK_FLAG(arg->flags, WIDTH) &&
		(arg->width > tmp_len))
		index = arg->width - tmp_len;
	if (CHK_FLAG(arg->flags, PREC) && (arg->precision > tmp_len))
		ft_memset(arg->buffer + index, '0', arg->precision - tmp_len);
	ft_memcpy(arg->buffer + index, tmp_str, tmp_len);
	ft_memcpy(arg->buffer + (index - 2), "0x", 2);
	free(tmp_str);
}

void	set_str(va_list *args, t_param *arg)
{
	char	*str;
	size_t	str_len;
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
	if (!CHK_FLAG(arg->flags, LEFT) && CHK_FLAG(arg->flags, PREC) &&
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
	char			*buf;

	c = (unsigned char)va_arg(*args, int);
	if (CHK_FLAG(arg->flags, LEFT))
		*(arg->buffer) = c;
	else
	{
		if (!arg->width)
			arg->width++;
		*(arg->buffer + arg->width - 1) = c;
	}
}

void	init_string(t_param *arg)
{
	char	c;

	c = 0;
	if (CHK_FLAG(arg->flags, WIDTH))
	{
		c = ' ';
		if (CHK_FLAG(arg->flags, ZERO) && !(CHK_FLAG(arg->flags, LEFT)))
			c = '0';
	}
	if (c)
		ft_memset(arg->buffer, c, arg->width);
}

int		format_output(va_list *args, t_param *arg)
{
	(void)args;
	init_string(arg);
	g_setf[arg->type](args, arg);
	return (0);
}
