/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:22:04 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2020/02/28 12:08:34 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_handle_percent(t_flags flags)
{
	int cont;

	cont = 0;
	if (flags.minus == 1)
		cont += ft_putstr_p("%", 1);
	cont += ft_handle_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		cont += ft_putstr_p("%", 1);
	return (cont);
}
