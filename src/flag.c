/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:27:25 by flohrel           #+#    #+#             */
/*   Updated: 2021/01/29 19:40:29 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



int		set_flag(char *field, char flag)
{
	return ((*field) |= flag);
}

int		check_flag(char field, char flag)
{
	return (field & flag);
}

void	clear_flag(char *field, char flag)
{
	(*field) &= ~(flag);
}
