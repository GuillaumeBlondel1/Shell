/*
** EPITECH PROJECT, 2024
** Shell
** File description:
** reading_terminal.c
*/

#include "../include/reading.h"

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

static char *reading_loop(void)
{
    temp_buffer_t buffer = {0};
    cursor_t cursor = {0};
    reading_char_type_t char_type = {0};

    cursor.front_cursor = 1;
    while (true) {
        char_type = get_input();
        if (char_type.type == BACK_TO_LINE) {
            break;
        }
        line_editing(&buffer, &cursor, char_type);
    }
    if (buffer.save_buffer != NULL) {
        free(buffer.save_buffer);
    }
    return buffer.raw_buffer;
}

char *reading_terminal(void)
{
    char *input = NULL;

    set_terminal_mode();
    input = reading_loop();
    unset_terminal_mode();
    printf("\n");
    return input;
}
