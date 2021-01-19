#include "printf.h"

char			*set_int(va_list *args, t_param *arg)
{
	int			nb;
	int			str_len;
	int			tmp_len;
	size_t		index;
	char		*nb_str;
	char		*tmp;

	nb_str = NULL;
	index = 0;
	nb = va_arg(*args, int);
	tmp = ft_itoa(nb);
	if (!tmp)
		return (NULL);
	tmp_len = number_format(arg, &tmp, ft_strlen(tmp));
	if (tmp_len == -1)
		return (NULL);
	str_len = n_str_alloc(arg, &nb_str, tmp_len);
	if (str_len == -1)
		return (NULL);
	if (!CHK_FLAG(arg->flags, LEFT))
		index = str_len - tmp_len;
	ft_memcpy(nb_str + index, tmp, tmp_len);
	free(tmp);
	return (nb_str);
}
