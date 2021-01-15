/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 04:37:34 by flohrel           #+#    #+#             */
/*   Updated: 2021/01/15 17:56:17 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		main(void)
{
	int		len = 97589;
//	printf("%x %X %08x %-8X %-8.3x %010.9x %0.0x\n", len, len, len, len, len, len, len);
	printf("%p %0.8p %-8p %-7.8p %010.9p %2.2p\n", len, len, len, len, len, len, len);
	ft_printf("%p %0.8p %-8p %-7.8p %010.9p %2.2p", len, len, len, len, len, len, len);
}
