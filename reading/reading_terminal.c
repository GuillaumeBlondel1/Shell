/*
** EPITECH PROJECT, 2024
** Shell
** File description:
** reading_terminal.c
*/

#include "../include/reading.h"

#include <stdio.h>
#include <stdbool.h>

static void reading_loop(temp_buffer_t *current_buffer)
{
    cursor_t cursor = {0};
    reading_char_type_t char_type = {0};

    cursor.front_cursor = 1;
    while (true) {
        char_type = get_input();
        buffering_allocation(current_buffer, char_type.c, &cursor, APPEND);
    }
}

char *reading_terminal(void)
{
    temp_buffer_t current_buffer = {0};

    set_terminal_mode();
    reading_loop(&current_buffer);
    unset_terminal_mode();
    return NULL;
}
