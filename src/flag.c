/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:27:25 by flohrel           #+#    #+#             */
/*   Updated: 2021/01/29 17:24:18 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		SET_FLAG(char *field, char flag)
{
	return (*field |= flag);
}

int		CHK_FLAG(char *field, char flag)
{
	return ((*field) & flag);
}

void	CLR_FLAG(char *field, char flag)
{
	*field &= ~(flag);
}
