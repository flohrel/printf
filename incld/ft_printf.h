/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 03:57:09 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/19 10:36:19 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "flag.h"
# include "libft.h"

# define BUF_SIZE	16384
# define SUCCESS	0
# define ERROR		-1
# define FALSE		0
# define TRUE		1
# define NULLSTR	"(null)"
# define NULLWCS	L"(null)"

typedef char			t_bool;

typedef struct			s_param
{
	int					flags;
	int					type;
	int					width;
	int					precision;
	char				buffer[BUF_SIZE];
	wchar_t				*wc_buf;
}						t_param;

typedef union			u_type
{
	char				c;
	unsigned char		uc;
	short int			si;
	short unsigned int	us;
	wchar_t				lc;
	int					i;
	unsigned int		ui;
	float				f;
	long				l;
	unsigned long		ul;
	long long			ll;
	unsigned long long	ull;
	double				lf;
	long double			llf;
	char				*s;
	wchar_t				*ls;
}						t_type;

typedef struct			s_float
{
	double				nb;
	long				integer;
	long				fractional;
	char				*int_s;
	char				*frac_s;
	int					afterpoint;
	int					tmp_len;
	int					index;
	t_bool				is_neg;
}						t_float;

extern char				g_types[13];
extern void				(*g_setf[])(va_list *, t_param *);
extern void				(*g_float_fun[])(va_list *, t_param *);

int						ft_printf(const char *str, ...);

/*
**		PARSE
*/
int						parse_param(va_list *args, t_param *arg,
					const char **str);
void					set_lenmod(t_param *arg, const char **str);
void					set_precision(va_list *args, t_param *arg,
					const char **str);
void					set_width(va_list *args, t_param *arg,
					const char **str);

/*
**		FORMAT
*/
int						format_output(va_list *args, t_param *arg);
int						number_format(t_param *arg, char **tmp, int tmp_len);
void					set_char(va_list *args, t_param *arg);
void					set_str(va_list *args, t_param *arg);
void					set_ptr(va_list *args, t_param *arg);
void					set_uint(va_list *args, t_param *arg);
void					set_int(va_list *args, t_param *arg);
void					set_hex(va_list *args, t_param *arg);
void					set_notype(va_list *args, t_param *arg);
void					set_count(va_list *args, int count);
void					set_sign(t_param *arg, int index, t_bool is_neg);
void					set_prefix(t_param *arg, int index);
void					set_wchar(va_list *args, t_param *arg);
void					set_wcs(va_list *args, t_param *arg);
void					set_float(va_list *args, t_param *arg);
unsigned long long		unsigned_lenmod(va_list *args, t_param *arg);
long long				signed_lenmod(va_list *args, t_param *arg);

/*
**		DISPLAY
*/
int						print_out(t_param *arg);

#endif
