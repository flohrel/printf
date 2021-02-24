/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:10:47 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/24 14:25:16 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_wcs(size_t len, t_param *arg)
{
	char	c;

	c = 0;
	if (check_flag(arg->flags, WIDTH))
	{
		c = ' ';
		if (check_flag(arg->flags, ZERO) && !(check_flag(arg->flags, LEFT)) &&
			(!check_flag(arg->flags, PREC) || (arg->type == 8)))
			c = '0';
	}
	if (c)
	{
		if (check_flag(arg->flags, LEFT))
			ft_memset(arg->buffer + len, c, arg->width - len);
		else
			ft_memset(arg->buffer, c, arg->width);
	}
}

void	set_wcs2(t_param *arg, char *wcs, int wcs_len)
{
	size_t			index;

	if (!wcs_len)
		wcs_len = 6;
	if (check_flag(arg->flags, PREC) && (arg->precision < wcs_len))
		wcs_len = arg->precision;
	index = 0;
	if (!check_flag(arg->flags, LEFT) && check_flag(arg->flags, WIDTH) &&
		(arg->width > wcs_len))
		index = arg->width - wcs_len;
	if (wcs)
		ft_memcpy(arg->buffer + index, wcs, wcs_len);
	else
		ft_memcpy(arg->buffer + index, NULLSTR, wcs_len);
}

void	set_wcs(va_list *args, t_param *arg)
{
	uint32_t	*wcs;
	char		*utf8;
	char		*wchars;
	char		*tmp;
	int			len;

	wcs = va_arg(*args, uint32_t *);
	wchars = ft_calloc(1, sizeof(char));
	*wchars = '\0';
	len = 0;
	while (wcs && (*wcs != 0))
	{
		utf8 = ft_uint_to_utf8(*wcs);
		len += ft_strlen(utf8);
		tmp = wchars;
		wchars = ft_strjoin(wchars, utf8);
		free(tmp);
		free(utf8);
		wcs++;
	}
	init_wcs(len, arg);
	set_wcs2(arg, wchars, len);
	free(wchars);
}

void	set_wchar(va_list *args, t_param *arg)
{
	uint32_t	wchar;
	char		*utf8;
	int			len;
	size_t		index;

	wchar = va_arg(*args, uint32_t);
	utf8 = ft_uint_to_utf8(wchar);
	len = ft_strlen(utf8);
	init_wcs(len, arg);
	index = 0;
	if (!check_flag(arg->flags, LEFT) && check_flag(arg->flags, WIDTH) &&
		(arg->width > len))
		index = arg->width - len;
	ft_memcpy(arg->buffer + index, utf8, len);
	free(utf8);
}
