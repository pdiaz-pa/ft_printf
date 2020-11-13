/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:47:07 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2020/02/28 12:08:34 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ft_handle_uinttt(char *u_num, t_flags flags)
{
	int cont;

	cont = 0;
	if (flags.dot >= 0)
		cont += ft_handle_width(flags.dot - 1, ft_strlen(u_num) - 1, 1);
	cont += ft_putstr_p(u_num, ft_strlen(u_num));
	return (cont);
}

static int	ft_handle_uintt(char *u_num, t_flags flags)
{
	int cont;

	cont = 0;
	if (flags.minus == 1)
		cont += ft_handle_uinttt(u_num, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(u_num))
		flags.dot = ft_strlen(u_num);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		cont += ft_handle_width(flags.width, 0, 0);
	}
	else
		cont += ft_handle_width(flags.width, ft_strlen(u_num), flags.zero);
	if (flags.minus == 0)
		cont += ft_handle_uinttt(u_num, flags);
	return (cont);
}

int			ft_handle_uint(unsigned int number, t_flags flags)
{
	int		cont;
	char	*u_num;

	cont = 0;
	number = (unsigned int)(4294967295 + 1 + number);
	if (flags.dot == 0 && number == 0)
	{
		cont += ft_handle_width(flags.width, 0, 0);
		return (cont);
	}
	u_num = ft_u_itoa(number);
	cont = ft_handle_uintt(u_num, flags);
	free(u_num);
	return (cont);
}
