/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 03:57:09 by flohrel           #+#    #+#             */
/*   Updated: 2020/12/30 21:00:24 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include "flag.h"

typedef struct	s_lst

	void			*data;
	struct s_lst	*next;
}				t_lst;

typedef struct	s_param
{
	char	type;
	char	flags;
	size_t	width;
	size_t	precision;
}				t_param;

# endif
