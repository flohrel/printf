/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 20:29:06 by flohrel           #+#    #+#             */
/*   Updated: 2021/01/29 19:35:43 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAG_H
# define FLAG_H

# define LEFT			1
# define ZERO			2
# define PREC			4
# define WIDTH			8
# define ALT			16
# define BLANK			32
# define SIGN			64

int		set_flag(char *field, char flag);
int		check_flag(char field, char flag);
void	clear_flag(char *field, char flag);

#endif
