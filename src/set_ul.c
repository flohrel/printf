#include "printf.h"

char			*set_ul(va_list *args, t_param *arg)
{
	unsigned long	ptr_addr;
	int				str_len;
	int				tmp_len;
	size_t			index;
	char			*nb_str;
	char			*tmp;

	nb_str = NULL;
	index = 2;
	ptr_addr = (unsigned long)va_arg(*args, void *);
	tmp = ft_ultoa_base(ptr_addr, "0123456789abcdef");
	if (!tmp)
		return (NULL);
	tmp_len = number_format(arg, &tmp, ft_strlen(tmp));
	if (tmp_len == -1)
		return (NULL);
	str_len = n_str_alloc(arg, &nb_str, tmp_len + 2);
	if (str_len == -1)
		return (NULL);
	if (!CHK_FLAG(arg->flags, LEFT))
		index = str_len - tmp_len;
	ft_memcpy(nb_str + index, tmp, tmp_len);
	ft_memcpy(nb_str + (index - 2), "0x", 2);
	free(tmp);
	return (nb_str);
}
