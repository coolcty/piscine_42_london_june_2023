LIST 		= ft_display_file.c
CFLAGS		= -Wall -Wextra -Werror
CC			= cc
INC			= -I./includes
SRC_DIRS    = ./srcs
OBJ_DIRS    = ${SRC_DIRS}
SRCS		= ${addprefix ${SRC_DIRS}/, ${LIST}}
OBJS 		= ${SRCS:${SRC_DIRS}/%.c=${OBJ_DIRS}/%.o}
NAME 		= ft_display_file 
RM          = rm -f
COM			= ar rc

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
