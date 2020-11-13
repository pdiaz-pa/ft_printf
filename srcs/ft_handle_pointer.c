/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:58:13 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2020/02/28 12:08:34 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ft_handle_stringg(char *pointer, t_flags flags)
{
	int cont;

	cont = 0;
	cont += ft_putstr_p("0x", 2);
	if (flags.dot >= 0)
	{
		cont += ft_handle_width(flags.dot, ft_strlen(pointer), 1);
		cont += ft_putstr_p(pointer, flags.dot);
	}
	else
		cont += ft_putstr_p(pointer, ft_strlen(pointer));
	return (cont);
}

int			ft_handle_pointer(unsigned long long num, t_flags flags)
{
	int		cont;
	char	*p;

	cont = 0;
	if (flags.dot == 0 && !num)
	{
		if (flags.width >= 0 && flags.minus == 0)
			(((cont += ft_handle_width(flags.width - 2, 0, 0))
			|| 1) && ((cont += ft_putstr_p("0x", 2)) || 1));
		else
			(((cont += ft_putstr_p("0x", 2)) || 1) &&
			((cont += ft_handle_width(flags.width - 2, 0, 0)) || 1));
		return (cont);
	}
	p = ft_utl_base(num, 16);
	p = ft_str_tolower(p);
	if ((size_t)flags.dot < ft_strlen(p))
		flags.dot = ft_strlen(p);
	if (flags.minus == 1)
		cont += ft_handle_stringg(p, flags);
	cont += ft_handle_width(flags.width, ft_strlen(p) + 2, 0);
	if (flags.minus == 0)
		cont += ft_handle_stringg(p, flags);
	free(p);
	return (cont);
}
