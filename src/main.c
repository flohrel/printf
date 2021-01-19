/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 04:37:34 by flohrel           #+#    #+#             */
/*   Updated: 2021/01/19 19:02:41 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		main(void)
{
	unsigned int	len = 987345;
	int				j = 15;
	int				n = 18;
	printf("%u %u %08u %-8u %-8.3u %011.9u %0.0u %*.*u\n", len, len, len, len, len, len, len, n, j, len);
	ft_printf("%u %u %08u %-8u %-8.3u %011.9u %0.0u %*.*u\n", len, len, len, len, len, len, len, n, j, len);
//	printf("%015x %021.16d %15X %017.14p %28.16p %2.2p %*.*p\n", len, len, len, &len, &len, &len, n, n, &len);
}
