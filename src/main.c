/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 04:37:34 by flohrel           #+#    #+#             */
/*   Updated: 2021/01/14 17:11:57 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		main(void)
{
	char c = 'Y';
	char *str = "ceci est un test";

	ft_printf("%-4.5s\t : ", str);
	printf("%%-4.5s : %-4.5s\n", str);
	ft_printf("%12.5s\t : ", str);
	printf("%%12.5s : %12.5s\n", str);
	ft_printf("%3.7s\t : ", str);
	printf("%%3.7s : %3.7s\n", str);
	ft_printf("%9s\t : ", str);
	printf("%%9s : %9s\n", str);
	ft_printf("%.0s\t : ", str);
	printf("%%.0s : %.0s\n", str);
//	printf("\n%%07.6d : %07.6d\n%%*x : %*x(* = 6)\n%%0.0u : %0.0u\n%%X : %X\n%%0-8u : %0-8u\n", len, 6, len, len, len, len);
//	printf("%%012.12p : %012.12p\n%%6.12p : %6.12p", len, len);
}
