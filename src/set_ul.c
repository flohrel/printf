#include "printf.h"

char			*set_ul(va_list *args, t_param *arg)
{
	unsigned long	ptr_addr;
	char			*tmp;
	char			*nb_str;
	size_t			str_len;

	ptr_addr = (unsigned long)va_arg(*args, void *);
	tmp = ft_ltoa_base(ptr_addr, "0123456789abcdef");
	if (!tmp)
		return (NULL);
	str_len = ft_strlen(tmp) + 2;
	nb_str = n_str_alloc(arg, str_len);
	nb_str[0] = '0';
	nb_str[1] = 'x';
	free(tmp);
	return (NULL);
}
