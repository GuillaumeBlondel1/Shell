##
## EPITECH PROJECT, 2024
## Shell
## File description:
## Makefile
##

SRC	:=	src/main.c													\
		prompt/display_prompt.c										\
		reading/reading_terminal.c									\
		reading/set_termios.c										\
		reading/get_input.c											\
		reading/buffering_allocation.c								\
		reading/line_editing.c										\
		reading/cursor_editing.c									\
		reading/buffer_editing.c									\

OBJ	:=	${SRC:.c=.o}

CFLAGS	:=	-Wall -Wextra -g3

BINARY	:=	shell

all:	compile

compile: $(OBJ)
	$(CC) -o $(BINARY) $(CFLAGS) $(OBJ)

clean:
	rm -f -r $(OBJ)

fclean:	clean
	rm -f $(BINARY)

re:	fclean	compile
