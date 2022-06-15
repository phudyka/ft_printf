# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 11:36:19 by phudyka           #+#    #+#              #
#    Updated: 2022/05/18 16:41:46 by phudyka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRCS		=	ft_printf.c ft_printf_utils.c	\

CC      = gcc

HEADER	= ft_printf.h

CFLAGS  = -Wall -Werror -Wextra

OBJS    = $(SRCS:.c=.o)

B_OBJS	= $(B_SRCS:.c=.o)

RM      = rm -f

AR      = ar -rc

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
all:		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
