# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/14 01:07:31 by rotrojan          #+#    #+#              #
#    Updated: 2019/12/04 06:33:44 by rotrojan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR		=		./srcs/
SRCS			=		ft_printf.c			\
						conversion.c		\
						convert_char.c


OBJS_DIR		=		./.objs/
OBJS			=		${SRCS:.c=.o}

INCLUDE_DIR		=		./include/
HEADER			=		ft_printf.h

LIB				=		libft.a
LIB_DIR			=		./lib/

NAME			=		libftprintf.a

CC				=		clang
AR				=		ar rcs
MKDIR			=		mkdir -p
RM				=		rm -f

CFLAGS			=		-Wall -Wextra -Werror -I${INCLUDE_DIR} -I./lib
						

all				:		${NAME}

${NAME}			:		${OBJS_DIR} $(addprefix ${OBJS_DIR}, ${OBJS})
	${AR} $@ $(addprefix ${OBJS_DIR}, ${OBJS})

${OBJS_DIR}%.o	:		${SRCS_DIR}%.c ${INCLUDE_DIR}${HEADER} ${LIB}
	${CC} ${CFLAGS} -c $< -o $@
${OBJS_DIR}		:
	mkdir -p ${OBJS_DIR}

${LIB}			:
	make -C ${LIB_DIR}

clean			:
	${RM} -r ${OBJS_DIR}
	make clean -C ${LIB_DIR}

fclean			:		clean
	${RM} ${NAME}
	make fclean -C ${LIB_DIR}

re				:		fclean ${OBJS_DIR} all

.PHONY	:			re			\
					all			\
					clean		\
					fclean
