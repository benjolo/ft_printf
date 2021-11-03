# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvalaria <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 16:10:38 by bvalaria          #+#    #+#              #
#    Updated: 2021/01/26 16:10:41 by bvalaria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printchar.c ft_printf.c ft_printhex.c ft_printint.c \
			ft_printstring.c ft_printu.c ft_utils.c ft_printpoint.c ft_secutils.c

OBJS	= ${SRCS:.c=.o}
CC 		= gcc
CFLAGS	= -Wall -Wextra -Werror -c
NAME	= libftprintf.a
RM		= /bin/rm -f

%.o: %.c
	${CC} ${CFLAGS} $<

${NAME} :	${OBJS}
			ar -rc ${NAME} ${OBJS}
			ranlib ${NAME}

all :		${NAME}

clean :
			${RM} ${OBJS}

fclean :	clean
			${RM} ${NAME}
			
re :		fclean all
	
.PHONY :	all clean fclean re
