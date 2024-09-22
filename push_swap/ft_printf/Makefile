# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dimirzoe <dimirzoe@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/29 09:47:25 by dimirzoe          #+#    #+#              #
#    Updated: 2024/01/05 10:52:18 by dimirzoe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c \
ft_putchar.c \
ft_putstr.c \
ft_putnbr.c \
ft_unbr.c \
ft_puthex.c \



OBJS = $(SRCS:.c=.o)

CC = cc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: clean all
