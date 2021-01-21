#include "printf.h"

char		*signed_nb_format(t_param *arg, char **tmp, t_bool is_neg)
{
	int			tmp_len;
	int			str_len;
	char		*nb_str;
	int			index;

	index = 0;
	tmp_len = number_format(arg, tmp, ft_strlen(*tmp));
	if (tmp_len == -1)
		return (NULL);
	if (is_neg)
	{
		index = 1;
		str_len = n_str_alloc(arg, &nb_str, tmp_len + 1);
	}
	else
		str_len = n_str_alloc(arg, &nb_str, tmp_len);
	if (str_len == -1)
		return (NULL);
	if (!CHK_FLAG(arg->flags, LEFT))
		index = str_len - tmp_len;
	if (is_neg)
	{
		if (CHK_FLAG(arg->flags, ZERO) && (str_len > tmp_len) &&
			!CHK_FLAG(arg->flags, PREC))
			nb_str[0] = '-';
		else
			nb_str[index - 1] = '-';
	}
	ft_memcpy(nb_str + index, *tmp, tmp_len);
	return (nb_str);
}

char		*set_int(va_list *args, t_param *arg)
{
	long		nb;
	char		*nb_str;
	char		*tmp;
	t_bool		is_neg;

	is_neg = FALSE;
	nb_str = NULL;
	nb = va_arg(*args, int);
	if (nb < 0)
	{
		is_neg = TRUE;
		nb = -(long)nb;
	}
	tmp = ft_itoa(nb);
	if (!tmp)
		return (NULL);
	nb_str = signed_nb_format(arg, &tmp, is_neg);
	free(tmp);
	return (nb_str);
}
