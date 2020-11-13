/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:42:08 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2020/03/02 11:09:56 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

static t_flags	ft_init_flags(void)
{
	t_flags	flags;

	flags.width = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.dot = -1;
	flags.star = 0;
	flags.type = 0;
	return (flags);
}

static int		ft_symbol_to_flag(const char *str, int i,
t_flags *flags, va_list args)
{
	while (str[i])
	{
		if (!ft_isconversion(str[i]) && !ft_isflag(str[i])
		&& !ft_isdigit(str[i]))
			break ;
		if (str[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (str[i] == '*')
			*flags = ft_width_flag(args, *flags);
		if (str[i] == '.')
			i = ft_dot_flag(str, i, flags, args);
		if (str[i] == '-')
			*flags = ft_minus_flag(*flags);
		if (ft_isdigit(str[i]))
			*flags = ft_digit_flag(str[i], *flags);
		if (ft_isconversion(str[i]))
		{
			flags->type = str[i];
			break ;
		}
		i++;
	}
	return (i);
}

static int		ft_handle_input(const char *str2, va_list args)
{
	int		i;
	int		cont;
	t_flags	flags;

	i = 0;
	cont = 0;
	while (!0)
	{
		flags = ft_init_flags();
		if (!str2[i])
			break ;
		else if (str2[i] != '%')
			cont += ft_putchar(str2[i]);
		else if (str2[i] == '%' && str2[i + 1])
		{
			i = ft_symbol_to_flag(str2, ++i, &flags, args);
			if (ft_isconversion(str2[i]))
				cont += ft_handle((char)flags.type, flags, args);
			else if (str2[i])
				cont += ft_putchar(str2[i]);
		}
		i++;
	}
	return (cont);
}

int				ft_printf(const char *str, ...)
{
	va_list		args;
	const char	*str2;
	int			cont;

	cont = 0;
	if (!(str2 = ft_strdup(str)))
		return (0);
	va_start(args, str);
	cont += ft_handle_input(str2, args);
	va_end(args);
	free((char *)str2);
	return (cont);
}
