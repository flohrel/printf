#include <stdio.h>
#include <unistd.h>
#include "printf.h"

int	main(void)
{
	printf("%d\n", -345);
	ft_printf("ft:%d\n", -345);
	printf("%i\n", -2534);
	ft_printf("%i\n", -2534);
	printf("%7.3i\n", -2384);
	ft_printf("%7.3i\n", -2384);
	printf("%7.7i\n", -534);
	ft_printf("%7.7i\n", -534);
	printf("%7.7i\n", 534);
	ft_printf("%7.7i\n", 534);
	printf("%7.3i\n", -9875);
	ft_printf("%7.3i\n", -9875);
	printf("%09.7i\n", -9875);
	ft_printf("%09.7i\n", -9875);
	printf("%03%\n");
	ft_printf("ft:%03%\n");
	printf("%0.02i\n", -645);
	ft_printf("%0.02i\n", -645);
	printf("%-6.4i\n", -745);
	ft_printf("%-6.4i\n", -745);
	printf("%-4.6i\n", -987);
	ft_printf("%-4.6i\n", -987);
	printf("%s\n", NULL);
	ft_printf("%s\n", NULL);
	printf("%7.3s\n", NULL);
	ft_printf("%7.3s\n", NULL);
	printf("%-8.5s\n", NULL);
	ft_printf("%-8.5s\n", NULL);
	printf("%09.2s\n", NULL);
	ft_printf("%09.2s\n", NULL);
	printf("{%.1c}\n", '\0');
	ft_printf("{%.1c}\n", '\0');
	printf("%09.002s\n", "WAiiiiiii");
	ft_printf("%09.002s\n", "WAiiiiiii");
}
