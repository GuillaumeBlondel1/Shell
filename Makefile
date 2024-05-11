##
## EPITECH PROJECT, 2024
## Shell
## File description:
## Makefile
##

SRC	:=	src/main.c	\

OBJ	:=	${SRC:.c=.o}

BINARY_NAME	:=	shell

CFLAGS	:=	-Wall -Wextra

all:	${BINARY_NAME}

${BINARY_NAME}:	${OBJ}
	$(CC) -o ${BINARY_NAME} ${OBJ} ${CFLAGS}

clean:
	rm -f -r ${OBJ}

fclean:	clean
	rm -f ${BINARY_NAME}

.PHONY: all re clean fclean
