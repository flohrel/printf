#include <stdio.h>
#include <unistd.h>
#include "printf.h"

void	char_test(void)
{
	printf("%8c.\n", 42);
	ft_printf("%8c.\n", 42);
	printf("%.8c.\n", 42);	
	ft_printf("%.8c.\n", 42);
	printf("%8.8c.\n", 42);
	ft_printf("%8.8c.\n", 42);
	printf("%8.c.\n", 42);
	ft_printf("%8.c.\n", 42);
	printf("%08c.\n", 42);
	ft_printf("%08c.\n", 42);
	printf("%-8c.\n", 42);
	ft_printf("%-8c.\n", 42);
	printf("%0.8c.\n", 42);
	ft_printf("%0.8c.\n", 42);
	printf("%05.8c.\n", 42);
	ft_printf("%05.8c.\n", 42);
	printf("%*.*c.\n", 0, 0, 42);
	ft_printf("%*.*c.\n", 0, 0, 42);
	printf("%.0c.\n", 42);
	ft_printf("%.0c.\n", 42);
	printf("{%5c}.\n", 0);
	ft_printf("{%5c}.\n", 0);
}

void	str_test(void)
{
	char *str = "Ceci est un test.";

	printf("%8s\n", str);
	ft_printf("%8s\n", str);
	printf("%.8s\n", str);
	ft_printf("%.8s\n", str);
	printf("%0.0s\n", str);
	ft_printf("%0.0s\n", str);
	printf("%8.3s\n", str);
	ft_printf("%8.3s\n", str);
	printf("%-.8s\n", str);
	ft_printf("%-.8s\n", str);
	printf("%09.8s\n", NULL);
	ft_printf("%09.8s\n", NULL);
	printf("%2.3s\n", NULL);
	ft_printf("%2.3s\n", NULL);
}

int		main(void)
{
	str_test();
}
