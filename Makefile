# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/15 01:44:07 by rotrojan          #+#    #+#              #
#    Updated: 2019/12/15 08:33:02 by rotrojan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR		=		./srcs/
SRCS			=		ft_printf.c									\
						parsing.c									\
						conversion.c								\
						convert_char.c								\
						convert_str.c								\
						convert_int.c								\
						convert_uint.c								\
						convert_ptr.c								\
						convert_hexlow.c							\
						convert_hexupp.c							\
						convert_percent.c

LIB_DIR			=		./lib/
LIB				=		ft_atoi_lite.c								\
						ft_bzero.c									\
						ft_isdigit.c

OBJS_DIR		=		./.objs/
OBJS			=		$(addprefix ${OBJS_DIR}, ${SRCS:.c=.o})		\
						$(addprefix ${OBJS_DIR}, ${LIB:.c=.o})

INCLUDE_DIR		=		./include/
HEADER			=		ft_printf.h

NAME			=		libftprintf.a

CC				=		clang
AR				=		ar rcs
MKDIR			=		mkdir -p
RM				=		rm -f

CFLAGS			=		-Wall -Wextra -Werror -I${INCLUDE_DIR}

vpath					%.c ./srcs/ ./lib/

all				:		${NAME}

${NAME}			:		${OBJS}
	${AR} $@ $^

${OBJS_DIR}%.o	:		%.c ${INCLUDE_DIR}${HEADER} | ${OBJS_DIR}
	${CC} ${CFLAGS} -c $< -o $@

${OBJS_DIR}		:
	mkdir -p ${OBJS_DIR}

clean			:
	${RM} -r ${OBJS_DIR}

fclean			:	
	@${MAKE} clean
	${RM} ${NAME}

re				:		
	@${MAKE} fclean
	@${MAKE} all

.PHONY	:			all			\
					clean		\
					fclean		\
					re

