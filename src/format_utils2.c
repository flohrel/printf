/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:55:28 by flohrel           #+#    #+#             */
/*   Updated: 2021/01/29 17:19:16 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	set_sign(t_param *arg, int index, t_bool is_neg)
{
	char	c;

	if (is_neg)
		c = '-';
	else
	{
		if (CHK_FLAG(&arg->flags, BLANK))
			c = ' ';
		else
			c = '+';
	}
	if (CHK_FLAG(&arg->flags, ZERO) && !(CHK_FLAG(&arg->flags, PREC)))
		*(arg->buffer) = c;
	else
		*(arg->buffer + (index - 1)) = c;
}

void	set_prefix(t_param *arg, int index)
{
	if (arg->type == 7)
		ft_memcpy(arg->buffer + index, "0X", 2);
	else
		ft_memcpy(arg->buffer + index, "0x", 2);
}

void	set_hex(va_list *args, t_param *arg)
{
	unsigned int	nb;
	int				tmp_len;
	size_t			index;
	char			*tmp;

	nb = (unsigned int)va_arg(*args, int);
	if (arg->type == 6)
		tmp = ft_ltoa_base(nb, "0123456789abcdef");
	else
		tmp = ft_ltoa_base(nb, "0123456789ABCDEF");
	if (!tmp)
		return ;
	tmp_len = number_format(arg, &tmp, ft_strlen(tmp));
	if (tmp_len == -1)
		return ;
	index = 0;
	if (CHK_FLAG(&arg->flags, ALT) && nb)
		index = 2;
	if (CHK_FLAG(&arg->flags, WIDTH) && (arg->width > tmp_len) &&
		!CHK_FLAG(&arg->flags, LEFT))
		index = arg->width - tmp_len;
	ft_memcpy(arg->buffer + index, tmp, tmp_len);
	if (CHK_FLAG(&arg->flags, ALT) && nb)
		set_prefix(arg, index - 2);
	free(tmp);
}

void	set_notype(va_list *args, t_param *arg)
{
	int	index;

	index = 0;
	(void)args;
	if (CHK_FLAG(&arg->flags, WIDTH) && (arg->width > 1) &&
		!CHK_FLAG(&arg->flags, LEFT))
		index = arg->width - 1;
	*(arg->buffer + index) = '%';
}

void	set_count(va_list *args, int count)
{
	int	*count_ptr;

	count_ptr = va_arg(*args, int *);
	*count_ptr = count;
}
