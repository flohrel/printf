/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:50:41 by flohrel           #+#    #+#             */
/*   Updated: 2021/01/23 13:57:10 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*set_char(va_list *args, t_param *arg)
{
	char			*str;
	int				len;

	len = arg->width;
	if (len < 1)
		len = 1;
	str = ft_calloc(len + 1, sizeof(char));
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
