#include <stdio.h>
#include <unistd.h>
#include "printf.h"

void	char_test(void)
{
	printf("%8c.\n", 42);
	ft_printf("%8c.\n", 42);
	printf("%8c.\n", 42);	
	ft_printf("%8c.\n", 42);
	printf("%88c.\n", 42);
	ft_printf("%88c.\n", 42);
	printf("%8c.\n", 42);
	ft_printf("%8c.\n", 42);
	printf("%8c.\n", 42);
	ft_printf("%8c.\n", 42);
	printf("%-8c.\n", 42);
	ft_printf("%-8c.\n", 42);
	printf("%8c.\n", 42);
	ft_printf("%8c.\n", 42);
	printf("%8c.\n", 42);
	ft_printf("%8c.\n", 42);
	printf("%*c.\n", 0, 42);
	ft_printf("%*c.\n", 0, 42);
	printf("%c.\n", 42);
	ft_printf("%c.\n", 42);
	printf("{%3c}\n", -0);
	ft_printf("{%3c}\n", -0);
}

void	str_test(void)
{
	char *str = "Ceci est un test.";

	printf("%8s\n", str);
	ft_printf("%8s\n", str);
	printf("%.8s\n", str);
	ft_printf("%.8s\n", str);
	printf("%.0s\n", str);
	ft_printf("%.0s\n", str);
	printf("%8.3s\n", str);
	ft_printf("%8.3s\n", str);
	printf("%-.8s\n", str);
	ft_printf("%-.8s\n", str);
	printf("%9.8s\n", NULL);
	ft_printf("%9.8s\n", NULL);
	printf("%2.3s\n", NULL);
	ft_printf("%2.3s\n", NULL);
	printf("%.*s\n", -3, "hello");
	ft_printf("%.*s\n", -3, "hello");
	printf("%-*.*s\n", -7, -3, str);
	ft_printf("%-*.*s\n", -7, -3, str);
}

void	ptr_test(void)
{
	char	*str = "Ceci est un test.";
;

	printf("%8p\n", str);
	ft_printf("%8p\n", str);
	printf("%16p\n", str);
	ft_printf("%16p\n", str);
	printf("%15p\n", str);
	ft_printf("%15p\n", str);
	printf("%16p\n", str);
	ft_printf("%16p\n", str);
	printf("%-15p\n", NULL);
	ft_printf("%-15p\n", NULL);
	printf("%9p\n", str);
	ft_printf("%9p\n", str);
	printf("%p\n", NULL);
	ft_printf("%p\n", NULL);
	printf("%2p\n", NULL);
	ft_printf("%2p\n", NULL);
	printf("%*p\n", 0, NULL);
	ft_printf("%*p\n", 0, NULL);
}

void	uint_test(void)
{
	printf("%8u\n", 62);
	ft_printf("%8u\n", 62);
	printf("%.16u\n", 21578);
	ft_printf("%.16u\n", 21578);
	printf("%15u\n", 42);
	ft_printf("%15u\n", 42);
	printf("%16.13u\n", 9587);
	ft_printf("%16.13u\n", 9587);
	printf("%-.8u\n", 9867);
	ft_printf("%-.8u\n", 9867);
	printf("%09.12u\n", 254);
	ft_printf("%09.12u\n", 254);
	printf("%2.3u\n", 0);
	ft_printf("%2.3u\n", 0);
	printf("%*.*u\n", 0, 0, 0);
	ft_printf("%*.*u\n", 0, 0, 0);
}

void	int_test(void)
{
	printf("%8i\n", -62);
	ft_printf("%8i\n", -62);
	printf("%.16d\n", -21578);
	ft_printf("%.16d\n", -21578);
	printf("%15i\n", INT_MIN);
	ft_printf("%15i\n", INT_MIN);
	printf("%16.13d\n", -9587);
	ft_printf("%16.13d\n", -9587);
	printf("%-.8i\n", -9867);
	ft_printf("%-.8i\n", -9867);
	printf("%09.12d\n", -254);
	ft_printf("%09.12d\n", -254);
	printf("%2.3d\n", 0);
	ft_printf("%2.3d\n", 0);
	printf("%*.*i\n", 0, 0, 0);
	ft_printf("%*.*i\n", 0, 0, 0);
}

void	hex_test(void)
{
	printf("%8x\n", -62);
	ft_printf("%8x\n", -62);
	printf("%.16X\n", -21578);
	ft_printf("%.16X\n", -21578);
	printf("%15x\n", -42);
	ft_printf("%15x\n", -42);
	printf("%16.13X\n", -9587);
	ft_printf("%16.13X\n", -9587);
	printf("%-.8x\n", -9867);
	ft_printf("%-.8x\n", -9867);
	printf("%09.12X\n", -254);
	ft_printf("%09.12X\n", -254);
	printf("%2.3x\n", 0);
	ft_printf("%2.3x\n", 0);
	printf("%*.*X\n", 0, 0, 0);
	ft_printf("%*.*X\n", 0, 0, 0);
}

void	notype_test(void)
{
	printf("%8%\n");
	ft_printf("%8%\n");
	printf("%.16%\n");
	ft_printf("%.16%\n");
	printf("%15%\n");
	ft_printf("%15%\n");
	printf("%16.13%\n");
	ft_printf("%16.13%\n");
	printf("%-.8%\n");
	ft_printf("%-.8%\n");
	printf("%09.12%\n");
	ft_printf("%09.12%\n");
	printf("%2.3%\n");
	ft_printf("%2.3%\n");
}

void	nfge_test(void)
{
	int		n = 0;

	printf("%f\n", 98.5467894123);
	printf("%f %sun truc %d %n %d\n", 98.5467894123, "un truc au pif", n, &n, n);
	printf("%d\n", n);
	printf("%e\n", 98.5467894123);
	printf("%g\n", 98.5467894123);
	printf("%6f\n", 98.5467894123);
	printf("%6.5f\n", 98.5497894123);
	printf("%4.8f\n", 98.5467894123);
	printf("%6.5e\n", 98.5467894123);
	printf("%4.8e\n", 98.5467894123);
	printf("%04f\n", 98.5467894123);
	printf("%-9g\n", 98.5467894123);
	printf("%-9f\n", 98.5467894123);
	printf("%-9e\n", 98.5467894123);
}

void	count_test(void)
{
	int	count, count2;

	printf("oiajwefioja ijargfijg%nfawefaf iuhawef\n", &count);
	ft_printf("oiajwefioja ijargfijg%nfawefaf iuhawef\n", &count2);
	printf("%d68 erte4 6q8e4r %n -> %d\n", count, &count, count);
	ft_printf("%d68 erte4 6q8e4r %n -> %d\n", count2, &count2, count2);
}

void	altflag_test(void)
{
	printf("%#8x\n", -62);
	ft_printf("%#8x\n", -62);
	printf("%#.16X\n", -21578);
	ft_printf("%#.16X\n", -21578);
	printf("%#15x\n", -42);
	ft_printf("%#15x\n", -42);
	printf("%#16.13X\n", -9587);
	ft_printf("%#16.13X\n", -9587);
	printf("%#-.8x\n", -9867);
	ft_printf("%#-.8x\n", -9867);
	printf("%#09.12X\n", -254);
	ft_printf("%#09.12X\n", -254);
	printf("%#2.3x\n", 0);
	ft_printf("%#2.3x\n", 0);
	printf("%#*.*X\n", 0, 0, 0);
	ft_printf("%#*.*X\n", 0, 0, 0);
}

void	sign_test(void)
{
	printf("%+8u\n", 62);
	ft_printf("%+8u\n", 62);
	printf("%+.16u\n", 21578);
	ft_printf("%+.16u\n", 21578);
	printf("%+15u\n", 42);
	ft_printf("%+15u\n", 42);
	printf("%+16.13u\n", 9587);
	ft_printf("%+16.13u\n", 9587);
	printf("%+-.8u\n", 9867);
	ft_printf("%+-.8u\n", 9867);
	printf("%+09.12u\n", 254);
	ft_printf("%+09.12u\n", 254);
	printf("%+2.3u\n", 0);
	ft_printf("%+2.3u\n", 0);
	printf("%+*.*u\n", 0, 0, 0);
	ft_printf("%+*.*u\n", 0, 0, 0);
	printf("%+8i\n", -62);
	ft_printf("%+8i\n", -62);
	printf("%+.16d\n", -21578);
	ft_printf("%+.16d\n", -21578);
	printf("%+15i\n", INT_MIN);
	ft_printf("%+15i\n", INT_MIN);
	printf("%+16.13d\n", -9587);
	ft_printf("%+16.13d\n", -9587);
	printf("%-4i\n", -9867);
	ft_printf("%-4i\n", -9867);
	printf("%+09.12d\n", -254);
	ft_printf("%+09.12d\n", -254);
	printf("%+2.3d\n", 0);
	ft_printf("%+2.3d\n", 0);
	printf("%+*.*i\n", 0, 0, 0);
	ft_printf("%+*.*i\n", 0, 0, 0);
	printf("%+8x\n", -62);
	ft_printf("%+8x\n", -62);
	printf("%+.16X\n", -21578);
	ft_printf("%+.16X\n", -21578);
	printf("%+15x\n", -42);
	ft_printf("%+15x\n", -42);
	printf("%+16.13X\n", -9587);
	ft_printf("%+16.13X\n", -9587);
	printf("%+-.8x\n", -9867);
	ft_printf("%+-.8x\n", -9867);
	printf("%+09.12X\n", -254);
	ft_printf("%+09.12X\n", -254);
	printf("%+2.3x\n", 0);
	ft_printf("%+2.3x\n", 0);
	printf("%+*.*X\n", 0, 0, 0);
	ft_printf("%+*.*X\n", 0, 0, 0);
}

int		main(void)
{
//	char_test();
//	str_test();
//	ptr_test();
//	uint_test();
//	int_test();
//	hex_test();
//	notype_test();
//	nfge_test();
//	count_test();
//	altflag_test();
	sign_test();
	return (0);
}
