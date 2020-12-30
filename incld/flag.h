/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 20:29:06 by flohrel           #+#    #+#             */
/*   Updated: 2020/12/30 20:30:56 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAG_H
# define FLAG_H

# define LEFT			(1 << 0) // 1
# define ZERO			(1 << 1) // 2
# define PREC			(1 << 2) // 4
# define WIDTH			(1 << 3) // 8

# define SET_FLAG(n, f)	((n) |= (f))
# define CLR_FLAG(n, f)	((n) &= ~(f))
# define TGL_FLAG(n, f)	((n) ^= (f))
# define CHK_FLAG(n, f)	((n) & (f))

#endif
