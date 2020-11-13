/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:38:43 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2020/02/27 16:17:31 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libf/libf.h"

typedef struct	s_flags
{
	int width;
	int minus;
	int zero;
	int dot;
	int star;
	int type;
}				t_flags;

int				ft_isflag(int c);
int				ft_isconversion (int c);
int				ft_isdigit(int c);
char			*ft_utl_base(unsigned long long number, int base);
int				ft_handle_char(char c, t_flags flags);
t_flags			ft_minus_flag(t_flags flags);
t_flags			ft_digit_flag(char c, t_flags flags);
t_flags			ft_width_flag(va_list args, t_flags flags);
int				ft_dot_flag(const char *str, int start, t_flags *flags,
va_list args);
int				ft_handle_string(char *str, t_flags flags);
int				ft_handle_int(int i, t_flags flags);
int				ft_handle_pointer(unsigned long long num, t_flags flags);
int				ft_handle_hex(unsigned int number, int lowercase,
t_flags flags);
int				ft_handle_percent(t_flags flags);
int				ft_handle_uint(unsigned int u_num, t_flags flags);
int				ft_handle_width(int width, int minus, int zero);
int				ft_handle(int c, t_flags flags, va_list args);
int				ft_printf(const char *str, ...);

#endif
