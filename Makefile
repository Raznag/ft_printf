# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile1                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etordjma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/01 16:10:46 by etordjma          #+#    #+#              #
#    Updated: 2019/02/23 17:52:23 by mzanouji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc
NAME = libftprintf
CFLAGS = -Wall -Wextra -Werror
HEADER = *.h
CPPFLAGS = -I $(HEADER)
PATHLIB = ../Libft/
LIB = ft
CLIB = -L $(PATHLIB) -l$(LIB)
SRC = *.c

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : lib
			@$(CC) $(CFLAGS) -c $(SRC) $(CPPFLAGS)
					@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(CLIB)

lib :
			@Make -C $(PATHLIB)

clean :
			@/bin/rm -f $(OBJS)
					@Make -C $(PATHLIB) clean

fclean : clean
			@/bin/rm -f $(NAME)
					@Make -C $(PATHLIB) fclean

re : fclean all
