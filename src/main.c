/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 04:37:34 by flohrel           #+#    #+#             */
/*   Updated: 2021/01/19 16:51:26 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		main(void)
{
	int		n = -5;
	int		j = 0;
//	printf("%x %X %08x %-8X %-8.3x %010.9x %0.0x\n", len, len, len, len, len, len, len);
//	printf("%015x %021.16d %15X %017.14p %28.16p %2.2p %*.*p\n", len, len, len, &len, &len, &len, n, n, &len);
	printf("%.*p\n", j, NULL);
	ft_printf("%.*p", j, NULL);
}
