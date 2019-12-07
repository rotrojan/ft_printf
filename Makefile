# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/14 01:07:31 by rotrojan          #+#    #+#              #
#    Updated: 2019/12/05 20:41:54 by rotrojan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR		=		./srcs/
SRCS			=		ft_printf.c			\
						convert_char.c		\
						ft_printf_utils1.c	\
						conversion.c


OBJS_DIR		=		./.objs/
OBJS			=		${SRCS:.c=.o}

INCLUDE_DIR		=		./include/
HEADER			=		ft_printf.h

#LIB_DIR			=		./lib/
#LIB				=		${LIB_DIR}libft.a
#LIB				=		${LIB_DIR}*.o

NAME			=		libftprintf.a

CC				=		clang
AR				=		ar rcs
MKDIR			=		mkdir -p
RM				=		rm -f

CFLAGS			=		-Wall -Wextra -Werror -I${INCLUDE_DIR} -I./lib
						

all				:		${NAME}

${NAME}			:		$(addprefix ${OBJS_DIR}, ${OBJS}) #{LIB}
	${AR} $@ $^

${OBJS_DIR}%.o	:		${SRCS_DIR}%.c ${INCLUDE_DIR}${HEADER} ${OBJS_DIR}
	${CC} ${CFLAGS} -c $< -o $@

${OBJS_DIR}		:
	mkdir -p ${OBJS_DIR}

${LIB}			:
	make -C ${LIB_DIR}

test			: all
	${CC} ${CFLAGS} -L. -lftprintf main_printf.c
	./a.out

clean			:
	${RM} -r ${OBJS_DIR}
#	make clean -C ${LIB_DIR}

fclean			:		clean
	${RM} ${NAME}
#	make fclean -C ${LIB_DIR}

re				:		fclean ${OBJS_DIR} all

.PHONY	:			re			\
					all			\
					clean		\
					fclean

