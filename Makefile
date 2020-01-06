# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/15 01:44:07 by rotrojan          #+#    #+#              #
#    Updated: 2019/12/23 03:23:32 by rotrojan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS_DIR		=		./srcs/
SRCS			=		ft_printf.c									\
						parsing.c									\
						conversion.c								\
						putnbr_buffer.c								\
						convert_char.c								\
						convert_str.c								\
						convert_int.c								\
						convert_uint.c								\
						convert_ptr.c								\
						convert_hexa.c							\
						convert_percent.c

LIB_DIR			=		./lib/
LIB				=		ft_atoi_lite.c								\
						ft_bzero.c									\
						ft_strlen.c									\
						ft_isdigit.c

OBJS_DIR		=		./.objs/
OBJS			=		$(addprefix ${OBJS_DIR}, ${SRCS:.c=.o})		\
						$(addprefix ${OBJS_DIR}, ${LIB:.c=.o})

DEPENDENCIES	=		${OBJS:.o=.d}

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

-include ${DEPENDENCIES}
${OBJS_DIR}%.o	:		%.c | ${OBJS_DIR}
	${CC} ${CFLAGS} -MMD -c $< -o $@

${OBJS_DIR}		:
	mkdir -p ${OBJS_DIR}

test			:		all
	clang -Wall -Wextra -Werror ../../main_printf.c -L. -lftprintf -I include

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

