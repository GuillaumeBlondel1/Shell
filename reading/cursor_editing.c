/*
** EPITECH PROJECT, 2024
** Shell
** File description:
** cursor_editing.c
*/

#include "../include/reading.h"

void cursor_shifting(temp_buffer_t *buffer,
    cursor_t *cursor, char arrow_key)
{
    switch (arrow_key) {
        case KEY_LEFT:
            if (cursor->front_cursor != 1) {
                cursor->front_cursor--;
                cursor->back_cursor--;
            }
            return;
        case KEY_RIGHT:
            if (cursor->back_cursor != buffer->size_raw_buffer) {
                cursor->front_cursor++;
                cursor->back_cursor++;
            }
            return;
        default:
            return;
    }
}

void cursor_shifting_start_line(cursor_t *cursor)
{
    for (int i = cursor->front_cursor; i != 1; i--) {
        cursor->front_cursor--;
        cursor->back_cursor--;
    }
}
