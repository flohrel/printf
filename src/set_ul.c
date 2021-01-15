#include "printf.h"

char			*set_ul(va_list *args, t_param *arg)
{
	unsigned long	l;
	char			*tmp;
	char			*nb_str;

	l = (unsigned long)va_arg(*args, void *);
	if (l < 0)
		tmp = ft_itoa_base(l, "0123456789abcdef", 1);
	else
		tmp = ft_itoa_base(l, "0123456789abcdef", 0);
	if (!tmp)
		return (NULL);
	nb_str = n_str_format
	free(tmp);
	return (NULL);
}
