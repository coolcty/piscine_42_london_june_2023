LIST 		= ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c 
CFLAGS		= -Wall -Wextra -Werror
CC			= cc
INC			= -I./includes
SRC_DIRS    = ./srcs
OBJ_DIRS    = ${SRC_DIRS}
SRCS		= ${addprefix ${SRC_DIRS}/, ${LIST}}
OBJS 		= ${SRCS:${SRC_DIRS}/%.c=${OBJ_DIRS}/%.o}
NAME 		= libft.a 
RM          = rm -f
COM			= ar rc

${OBJ_DIRS}/%.o: ${SRC_DIRS}/%.c		
			${CC} ${CFLAGS} -c $< -o $@ ${INC}

${NAME}: 	${OBJS}
			${COM} ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:         fclean all
