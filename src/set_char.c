/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:50:41 by flohrel           #+#    #+#             */
/*   Updated: 2021/01/14 12:08:10 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*set_char(va_list *args, t_param *arg)
{
	unsigned char	c;
	char			*str;
	int				len;

	c = va_arg(*args, int);
	len = arg->width;
	if (len < 1)
		len = 1;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_memset(str, ' ', len);
	if (CHK_FLAG(arg->flags, LEFT))
		str[0] = c;
	else
		str[len - 1] = c;
	str[len] = '\0';
	return (str);
}
