# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rteles <rteles@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 20:42:26 by rteles            #+#    #+#              #
#    Updated: 2022/04/12 22:50:01 by rteles           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES	=	ft_so_long.c

OBJECTS	=	$(SOURCES:.c=.o)

NAME	= 	so_long

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

all: $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(OBJECTS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -Imlx -c $< -o $@

clean:
	$(RM) $(OBJECTS)
	
fclean: clean

re:		fclean $(NAME)

.PHONY: $(NAME) all clean fclean re