LIST 		= operations.c ft_op.c ft_putnbr.c  ft_strlen.c  main.c ft_atoi.c
CFLAGS		= -Wall -Wextra -Werror
CC			= cc
INC			= -I./includes
SRC_DIRS    = ./srcs
OBJ_DIRS    = ${SRC_DIRS}
SRCS		= ${addprefix ${SRC_DIRS}/, ${LIST}}
OBJS 		= ${SRCS:${SRC_DIRS}/%.c=${OBJ_DIRS}/%.o}
NAME 		= do-op
RM          = rm -f

${OBJ_DIRS}/%.o: ${SRC_DIRS}/%.c		
			${CC} ${CFLAGS} -c $< -o $@ ${INC}

${NAME}: 	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:         fclean all
