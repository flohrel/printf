/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:55:28 by flohrel           #+#    #+#             */
/*   Updated: 2021/01/26 17:09:19 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	set_hex(va_list *args, t_param *arg)
{
	unsigned int	nb;
	int				tmp_len;
	size_t			index;
	char			*tmp;

	index = 0;
	nb = (unsigned int)va_arg(*args, int);
	if (arg->type == 6)
		tmp = ft_ltoa_base(nb, "0123456789abcdef");
	else
		tmp = ft_ltoa_base(nb, "0123456789ABCDEF");
	if (!tmp || (tmp_len = number_format(arg, &tmp, ft_strlen(tmp))) == -1)
		return ;
	if (CHK_FLAG(arg->flags, WIDTH) && (arg->width > tmp_len) &&
		!CHK_FLAG(arg->flags, LEFT))
		index = arg->width - tmp_len;
	ft_memcpy(arg->buffer + index, tmp, tmp_len);
	free(tmp);
}

void	set_notype(va_list *args, t_param *arg)
{
	int	index;

	index = 0;
	(void)args;
	if (CHK_FLAG(arg->flags, WIDTH) && (arg->width > 1) &&
		!CHK_FLAG(arg->flags, LEFT))
		index = arg->width - 1;
	*(arg->buffer + index) = '%';
}

void	set_count(va_list *args, int count)
{
	int	*count_ptr;

	count_ptr = va_arg(*args, int *);
	*count_ptr = count;
}
