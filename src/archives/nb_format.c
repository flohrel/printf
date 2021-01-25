size_t	number_format(t_param *arg, char **tmp, size_t tmp_len)
{
	char	*nb_str;

	if (CHK_FLAG(arg->flags, PREC))
	{
		if (arg->precision > tmp_len)
		{
			nb_str = ft_calloc(arg->precision, sizeof(char));
			if (!nb_str)
				return (-1);
			ft_memset(nb_str, '0', arg->precision);
			ft_memcpy(nb_str + (arg->precision - tmp_len), *tmp, tmp_len);
			free(*tmp);
			*tmp = nb_str;
			return (arg->precision);
		}
		if (!arg->precision && (tmp_len == 1) && (**tmp == '0'))
		{
			*tmp = NULL;
			return (0);
		}
	}
	return (tmp_len);
}

size_t	n_str_alloc(t_param *arg, char **nb_str, size_t nb_len)
{
	size_t	str_len;
	char	c;

	c = 0;
	str_len = nb_len;
	if (CHK_FLAG(arg->flags, PREC) && (arg->precision > str_len))
		str_len = arg->precision;
	if (CHK_FLAG(arg->flags, WIDTH) && (arg->width > str_len))
	{
		if (CHK_FLAG(arg->flags, ZERO) && !(CHK_FLAG(arg->flags, LEFT)) &&
			!CHK_FLAG(arg->flags, PREC))
			c = '0';
		else
			c = ' ';
		str_len = arg->width;
	}
	*nb_str = ft_calloc(str_len + 1, sizeof(char));
	if (!nb_str)
		return (-1);
	if (c)
		ft_memset(*nb_str, c, str_len);
	*((*nb_str) + str_len) = '\0';
	return (str_len);
}

