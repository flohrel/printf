/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 04:37:34 by flohrel           #+#    #+#             */
/*   Updated: 2021/01/20 15:11:54 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int		(*fptr[])(const char *, ...) = { ft_printf, printf };

int		main(void)
{
//	unsigned int	len = 987345;
//	int				j = 15;
//	int				n = 18;
	
	printf("Hello %.s.\n", "Florian");
	ft_printf("Hello %.s.\n", "Florian");
	write(1, NULL, 5);
//	printf("%015x %021.16d %15X %017.14p %28.16p %2.2p %*.*p\n", len, len, len, &len, &len, &len, n, n, &len);
}
