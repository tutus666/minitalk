NAME = minitalk

SERVER = server

CLIENT = client

SRCS = server.c

SRCC = client.c

SRCU = ft_atoi.c ft_putnbr_fd.c ft_putstr_fd.c ft_strjoin.c ft_strlen.c ft_str_is_digit.c

SRCS_BONUS = server_bonus.c

SRCC_BONUS = client_bonus.c

SERVER_FILE = ${addprefix srcs/,${SRCS}}

CLIENT_FILE = ${addprefix srcs/, ${SRCC}}

UTILS_FILE = ${addprefix utils/, ${SRCU}}

SERVER_FILE_BONUS = ${addprefix srcs/,${SRCS_BONUS}}

CLIENT_FILE_BONUS = ${addprefix srcs/, ${SRCC_BONUS}}

OBJS = ${SERVER_FILE:.c=.o}

OBJC = ${CLIENT_FILE:.c=.o}

OBJU = ${UTILS_FILE:.c=.o}

OBJS_BONUS = ${SERVER_FILE_BONUS:.c=.o}

OBJC_BONUS = ${CLIENT_FILE_BONUS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c -I./includes/ $< -o ${<:.c=.o}

all:
	@${MAKE} --no-print-directory ${NAME}

${NAME}: ${SERVER} ${CLIENT}
	
${SERVER}:	${OBJS} ${OBJU}
	${CC} ${CFLAGS} $^ -o $@

${CLIENT}:	${OBJC} ${OBJU}
	${CC} ${CFLAGS} $^ -o $@

bonus: ${OBJS_BONUS} ${OBJC_BONUS} ${OBJU}
	${CC} ${CFLAGS} ${OBJS_BONUS} ${OBJU} -o ${SERVER}
	${CC} ${CFLAGS} ${OBJC_BONUS} ${OBJU} -o ${CLIENT}

clean:
	rm -rf ${OBJS} ${OBJC} ${OBJU} ${OBJS_BONUS} ${OBJC_BONUS}

fclean:		clean
	rm -rf ${NAME} ${CLIENT} ${SERVER}

re:			fclean	all

.PHONY:		all clean fclean re ${NAME}
