# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocalder <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 18:11:18 by jocalder          #+#    #+#              #
#    Updated: 2024/10/24 23:17:56 by jocalder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= libftprintf.a

SRCS	= ft_printf_utils.c \
			ft_printf.c \
			ft_putptr.c \

OBJS	= $(SRCS:.c=.o)

CC	= cc

FLAGS	= -Wall -Werror -Wextra

all: $(NAME)

%.o: %.c
	cc $(FLAGS) -c $< -o $@ -I ./

$(NAME): 
	cc $(FLAGS) -c $(SRCS) -I ./
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 


