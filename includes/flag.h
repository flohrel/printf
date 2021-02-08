/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 20:29:06 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/08 14:06:37 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAG_H
# define FLAG_H

# define LEFT			0x1
# define ZERO			0x2
# define PREC			0x4
# define WIDTH			0x8
# define ALT			0x10
# define BLANK			0x20
# define SIGN			0x40

# define LMOD_H			0x80
# define LMOD_HH		0x100
# define LMOD_L			0x200
# define LMOD_LL		0x400
# define LMOD			0x780

int		set_flag(int *field, int flag);
int		check_flag(int field, int flag);
void	clear_flag(int *field, int flag);

#endif
