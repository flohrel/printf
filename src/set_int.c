#include "printf.h"

char		*signed_nb_format(t_param *arg, char *tmp)
{
	int			tmp_len;
	int			str_len;
	char		*nb_str;
	t_bool		is_neg;

	is_neg = FALSE;
	if (*tmp == '-')
	{
		is_neg = TRUE;
	}
	tmp_len = number_format(arg, &tmp, ft_strlen(tmp));
	if (tmp_len == -1)
		return (NULL);
	str_len = n_str_alloc(arg, &nb_str, tmp_len);
	if (str_len == -1)
		return (NULL);
	if (!CHK_FLAG(arg->flags, LEFT))
		ft_memcpy(nb_str + (str_len - tmp_len), tmp, tmp_len);
	ft_memcpy(nb_str, tmp, tmp_len);
	return (nb_str);
}

char		*set_int(va_list *args, t_param *arg)
{
	int			nb;
	char		*nb_str;
	char		*tmp;

	nb_str = NULL;
	index = 0;
	nb = va_arg(*args, int);
	tmp = ft_itoa(nb);
	if (!tmp)
		return (NULL);
	nb_str = signed_nb_format(arg, tmp);
	free(tmp);
	return (nb_str);
}
