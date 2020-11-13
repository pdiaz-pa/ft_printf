/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 17:39:36 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2020/02/28 12:08:34 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int			ft_handle_stringg(char *str, t_flags flags)
{
	int cont;

	cont = 0;
	if (flags.dot >= 0)
	{
		cont += ft_handle_width(flags.dot, ft_strlen(str), 0);
		cont += ft_putstr_p(str, flags.dot);
	}
	else
		cont += ft_putstr_p(str, ft_strlen(str));
	return (cont);
}

int			ft_handle_string(char *str, t_flags flags)
{
	int cont;

	cont = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		cont += ft_handle_stringg(str, flags);
	if (flags.dot >= 0)
		cont += ft_handle_width(flags.width, flags.dot, 0);
	else
		cont += ft_handle_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		cont += ft_handle_stringg(str, flags);
	return (cont);
}
