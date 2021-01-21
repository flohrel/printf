/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 03:57:09 by flohrel           #+#    #+#             */
/*   Updated: 2021/01/20 14:30:53 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

/* TEMP */
# include <stdio.h>

# include <stdarg.h>
# include "flag.h"
# include "../libft/incld/libft.h"

# define BUF_SIZE	4096
# define SUCCESS	0
# define ERROR		-1
# define FALSE		0
# define TRUE		1

typedef char	t_bool;

typedef struct	s_param
{
	char		flags;
	int			type;
	size_t		width;
	size_t		precision;
	char		buffer[BUF_SIZE];
}				t_param;

extern char		g_types[9];
//extern char		*(*g_setf[])(va_list *, t_param *);

int				ft_printf(const char *str, ...);
int				parse_param(va_list *args, t_param *arg, const char **str);
int				format_output(va_list *args, t_param *arg);
int				number_format(t_param *arg, char **tmp, size_t tmp_len);
int				n_str_alloc(t_param *arg, char **nb_str, size_t nb_len);
/*char			*set_notype(va_list *args, t_param *arg);
char			*set_char(va_list *args, t_param *arg);
char			*set_str(va_list *args, t_param *arg);
char			*set_ul(va_list *args, t_param *arg);
char			*set_int(va_list *args, t_param *arg);
char			*set_uint(va_list *args, t_param *arg);
char			*set_hex(va_list *args, t_param *arg);*/

#endif
