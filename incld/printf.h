/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 03:57:09 by flohrel           #+#    #+#             */
/*   Updated: 2021/01/29 15:17:38 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include "flag.h"
# include "../libft/incld/libft.h"

# define BUF_SIZE	16384
# define SUCCESS	0
# define ERROR		-1
# define FALSE		0
# define TRUE		1
# define NULLSTR	"(null)"

typedef char	t_bool;

typedef struct	s_param
{
	char		flags;
	int			type;
	int			width;
	int			precision;
	char		buffer[BUF_SIZE];
}				t_param;

extern char		g_types[10];
extern void		(*g_setf[])(va_list *, t_param *);

int				ft_printf(const char *str, ...);
int				parse_param(va_list *args, t_param *arg, const char **str);
int				format_output(va_list *args, t_param *arg);
int				number_format(t_param *arg, char **tmp, int tmp_len);
void			set_char(va_list *args, t_param *arg);
void			set_str(va_list *args, t_param *arg);
void			set_ptr(va_list *args, t_param *arg);
void			set_uint(va_list *args, t_param *arg);
void			set_int(va_list *args, t_param *arg);
void			set_hex(va_list *args, t_param *arg);
void			set_notype(va_list *args, t_param *arg);
void			set_count(va_list *args, int count);
void			set_sign(t_param *arg, int index, t_bool is_neg);
void			set_prefix(t_param *arg, int index);
int				print_out(t_param *arg);

#endif
