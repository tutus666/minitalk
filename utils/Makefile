NAME = libft.a

SRCS =	ft_putnbr_fd.c ft_atoi.c ft_strjoin.c ft_strlen.c ft_putstr_fd.c

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS =	-Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c -I./../includes/ $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	ar -rcs $@ $^

all:		${NAME}

clean:
	rm -rf ${OBJS}

fclean:		clean
	rm -rf ${NAME}

re:			fclean	all

.PHONY:		all clean fclean re
