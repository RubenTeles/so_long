# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rteles <rteles@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 20:42:26 by rteles            #+#    #+#              #
#    Updated: 2022/05/12 00:15:37 by rteles           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES	=	./get_next_line/get_next_line.c \
			./get_next_line/get_next_line_utils.c \
			./ft_printf/ft_printf.c \
			./ft_printf/ft_printf_utils.c \
			./ft_printf/ft_print_unsigned_decimal.c \
			ft_path.c \
			ft_so_long.c \
			ft_so_long_utils.c \
			ft_animation_1.c \
			ft_animation_2.c \
			ft_animation_3.c \
			ft_animation_4.c \
			ft_method.c \
			ft_verification.c \
			ft_itoa.c

OBJECTS	=	$(SOURCES:.c=.o)

NAME	= 	so_long

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

AR		= ar -rcs

all: $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(OBJECTS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	$(RM) $(OBJECTS)
	
fclean: clean

re:		fclean $(NAME)

.PHONY: $(NAME) all clean fclean re
