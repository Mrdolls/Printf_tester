# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgingast <mgingast@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 09:08:55 by mgingast          #+#    #+#              #
#    Updated: 2025/05/22 21:25:12 by mgingast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = \
t_printf.c



INCLUDES = -Iincludes

.c.o:
	cc $(INCLUDES) -c $< -o ${<:.c=.o}

OFILES = $(SRCS:.c=.o)

CFLAGS = -fPIC

NAME = t_printf.a

all: $(NAME)

$(NAME): $(OFILES)
	ar rc $(NAME) $(OFILES)


clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
