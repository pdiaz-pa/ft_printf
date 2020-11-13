/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:49:23 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2020/02/28 12:08:34 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBF_H
# define LIBF_H

# include <unistd.h>
# include <stdlib.h>

int			ft_isdigit(int c);
int			ft_tolower(int c);
char		*ft_itoa(int n);
int			ft_putchar(char c);
char		*ft_str_tolower(char *str);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *str);
int			ft_putstr_p(char *str, int precision);
char		*ft_u_itoa(unsigned int n);
char		*ft_utl_base(unsigned long long number, int base);

#endif
