/*
** EPITECH PROJECT, 2024
** Shell
** File description:
** set_termios.c
*/

#include <termios.h>
#include <string.h>

struct termios origin_mode = {0};

void set_terminal_mode(void)
{
    struct termios new_mode = {0};

    tcgetattr(0, &origin_mode);
    memcpy(&new_mode, &origin_mode, sizeof(struct termios));
    new_mode.c_lflag = ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &new_mode);
}

void unset_terminal_mode(void)
{
    tcsetattr(0, TCSANOW, &origin_mode);
}
