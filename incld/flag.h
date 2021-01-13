/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 20:29:06 by flohrel           #+#    #+#             */
/*   Updated: 2021/01/13 13:59:58 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAG_H
# define FLAG_H

# define LEFT			(1 << 0) // 1 '-'
# define ZERO			(1 << 1) // 2 '0'
# define PREC			(1 << 2) // 4 '.'
# define WIDTH			(1 << 3) // 8 -> width
# define ALT			(1 << 4) // 16 '#'
# define BLANK			(1 << 5) // 32 ' '
# define SIGN			(1 << 6) // 64 '+'

# define SET_FLAG(n, f)	((n) |= (f))
# define CLR_FLAG(n, f)	((n) &= ~(f))
# define TGL_FLAG(n, f)	((n) ^= (f))
# define CHK_FLAG(n, f)	((n) & (f))

#endif
