/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 03:57:09 by flohrel           #+#    #+#             */
/*   Updated: 2020/12/31 17:23:52 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include "flag.h"

# define SUCCESS	0
# define ERROR		-1
# define FALSE		0
# define TRUE		1

typedef char	t_bool;

typedef struct	s_param
{
	char	type;
	char	flags;
	size_t	width;
	size_t	precision;
	char	*s;
}				t_param;

# endif
