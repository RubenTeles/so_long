# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rteles <rteles@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 20:42:26 by rteles            #+#    #+#              #
#    Updated: 2023/04/10 17:29:48 by rteles           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ORANGE = \033[0;33m
RED = \033[0;31m
PURPLE = \033[1;35m
CYAN = \033[3;36m
ORANG2 = \033[2;33m
GREY1 = \033[1;30m
GREY2 = \033[2;37m
WHITE = \033[0;37m
GREEN = \033[2;32m
OTHER = \033[9;34m
OTHE2 = \033[4;34m
R1 = \033[2;31m

CC			= 	gcc -g
CFLAGS		= 	-Wall -Wextra -Werror
RM			= 	/bin/rm -f
NAME		= 	so_long

INCLUDES	= 	./hdr

SRCS		= 	$(shell find src/ -name '*.c')
OBJS		= 	$(SRCS:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -I$(INCLUDES) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -I$(INCLUDES) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	@$(RM) $(OBJS)
	@echo "$(RED)REMOVED OBJECT FILES\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)REMOVED EXECUTABLE\033[0m"

re: fclean all

.PHONY: $(NAME) all clean fclean re
