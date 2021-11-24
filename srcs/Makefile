NAME = utils.a

SERVER = server

CLIENT = client

SRCS = server.c

SRCC = client.c

OBJS = ${SRCS:.c=.o}

OBJC = ${SRCC:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c -I./includes/ $< -o ${<:.c=.o}

${NAME}:
	make -C ./../utils/
	cp ./../utils/libft.a ${NAME}
	make ${SERVER}
	make ${CLIENT}

all:		${NAME}

${SERVER}:	${NAME} ${OBJS}
	${CC} ${CFLAGS} $^ -o $@
	
${CLIENT}:	${NAME} ${OBJC}
	${CC} ${CFLAGS} $^ -o $@

clean:
	rm -rf ${OBJS} ${OBJC}
	make clean -C ./../utils

fclean:		clean
	rm -rf ${NAME} ${CLIENT} ${SERVER}
	make fclean -C ./../utils

re:			fclean	all

.PHONY:		all clean fclean re
