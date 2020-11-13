# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/17 10:56:17 by pdiaz-pa          #+#    #+#              #
#    Updated: 2020/02/28 12:39:33 by pdiaz-pa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = 	ft_printf.c \
		srcs/ft_handle_char.c \
		srcs/ft_handle_flags.c \
		srcs/ft_handle_string.c \
		srcs/ft_handle_int.c \
		srcs/ft_handle_uint.c \
		srcs/ft_handle_percent.c \
		srcs/ft_handle_width.c \
		srcs/ft_handle_percent.c \
		srcs/ft_handle_pointer.c \
		srcs/ft_handle_hex.c \
		srcs/ft_handle.c \
		libf/ft_isdigit.c \
		libf/ft_putchar.c \
		libf/ft_putstr_p.c \
		libf/ft_itoa.c \
		libf/ft_u_itoa.c \
		libf/ft_str_tolower.c \
		libf/ft_strdup.c \
		libf/ft_strlen.c \
		libf/ft_tolower.c \
		libf/ft_utl_base.c 
		
		
	
	
	
		

OBJECTS = ft_printf.o \
		ft_handle_char.o \
		ft_handle_flags.o \
		ft_handle_string.o \
		ft_handle_int.o \
		ft_handle_uint.o \
		ft_handle_width.o \
		ft_handle_percent.o \
		ft_handle_pointer.o \
		ft_handle_hex.o \
		ft_handle.o \
		ft_isdigit.o \
		ft_putchar.o \
		ft_putstr_p.o \
		ft_itoa.o \
		ft_u_itoa.o \
		ft_str_tolower.o \
		ft_strdup.o \
		ft_strlen.o \
		ft_tolower.o \
		ft_utl_base.o 
		



INCLUDES = inc/ft_printf.h


all: $(NAME)

$(NAME): $(OBJECTS)

$(OBJECTS): $(SRCS) $(INCLUDES)
	@gcc -Wextra -Werror -Wall -c $(SRCS)
	@ar rcs $(NAME) $(OBJECTS)

clean:
	rm -rf $(OBJECTS)
	
fclean: clean
	rm -rf $(NAME)

re: fclean all
bonus:
