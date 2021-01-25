#include "printf.h"

char			*set_ul(va_list *args, t_param *arg)
{
	unsigned long	ptr_addr;
	int				str_len;
	char			*nb_str;

	nb_str = NULL;
	tmp_len = number_format(arg, &tmp, ft_strlen(tmp));
	str_len = n_str_alloc(arg, &nb_str, tmp_len + 2);
	if (str_len == -1)
		return (NULL);
	free(tmp);
	return (nb_str);
}
