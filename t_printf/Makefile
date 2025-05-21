# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgingast <mgingast <mgingast@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 09:08:55 by mgingast          #+#    #+#              #
#    Updated: 2025/05/21 19:48:55 by mgingast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = \
t_printf.c



INCLUDES = -Iincludes

.c.o:
	cc $(INCLUDES) $(CFLAGS) -c $< -o ${<:.c=.o}

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
