#include "printf.h"

char			*set_hex(va_list *args, t_param *arg)
{
	unsigned int	nb;
	int				str_len;
	int				tmp_len;
	size_t			index;
	char			*nb_str;
	char			*tmp;

	nb_str = NULL;
	index = 0;
	nb = (unsigned int)va_arg(*args, int);
	if (arg->type == 6)
		tmp = ft_ltoa_base(nb, "0123456789abcdef");
	else
		tmp = ft_ltoa_base(nb, "0123456789ABCDEF");
	if (!tmp)
		return (NULL);
	if ((tmp_len = number_format(arg, &tmp, ft_strlen(tmp))) == -1 ||
		(str_len = n_str_alloc(arg, &nb_str, tmp_len)) == -1)
		return (NULL);
	if (!CHK_FLAG(arg->flags, LEFT))
		index = str_len - tmp_len;
	ft_memcpy(nb_str + index, tmp, tmp_len);
	free(tmp);
	return (nb_str);
}
