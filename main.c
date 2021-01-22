#include <stdio.h>
#include <unistd.h>
#include "printf.h"

int	main(void)
{
	printf("%8c.\n", 42);
	printf("%.8c.\n", 42);
	printf("%8.8c.\n", 42);
	printf("%8.c.\n", 42);
	printf("%08c.\n", 42);
	printf("%-8c.\n", 42);
	printf("%0.8c.\n", 42);
	printf("%05.8c.\n", 42);
	printf("%*.*c.\n", 0, 0, 42);
	printf("%.0c.\n", 42);
	printf("{%5c}.\n", 0);
	ft_printf("%8c.\n", 42);
	ft_printf("%.8c.\n", 42);
	ft_printf("%8.8c.\n", 42);
	ft_printf("%8.c.\n", 42);
	ft_printf("%08c.\n", 42);
	ft_printf("%-8c.\n", 42);
	ft_printf("%0.8c.\n", 42);
	ft_printf("%05.8c.\n", 42);
	ft_printf("%*.*c.\n", 0, 0, 42);
	ft_printf("%.0c.\n", 42);
	ft_printf("{%5c}.\n", 0);
}
