/*
** EPITECH PROJECT, 2024
** Shell
** File description:
** line_editing.c
*/

#include "../include/reading.h"

#include <stdio.h>

static void cursor_shifting(temp_buffer_t *buffer,
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

static void display_input(temp_buffer_t *buffer, cursor_t *cursor)
{
    if (buffer->raw_buffer != NULL) {
        printf("%s", buffer->raw_buffer);
        fflush(stdout);
    }
    for (int i = buffer->size_raw_buffer; i > cursor->back_cursor; i--) {
        printf(MOVE_CURSOR_LEFT);
    }
}

static void clear_input(temp_buffer_t *buffer, cursor_t *cursor)
{
    for (int i = cursor->back_cursor; i < buffer->size_raw_buffer; i++) {
        printf(MOVE_CURSOR_RIGHT);
    }
    for (int i = buffer->size_raw_buffer; i > 0; i--) {
        printf(ERASE_CHAR);
    }
}

static void buffer_back_editing(temp_buffer_t *buffer, cursor_t *cursor, char c)
{
    switch (c) {
        case 27:
            return;
        case 127:
            buffering_allocation(buffer, 0, cursor, DEL);
            return;
        case 51:
            buffering_allocation(buffer, 0, cursor, SUPP);
            return;
        default:
            buffering_allocation(buffer, c, cursor, APPEND);
            return;
    }
}

void line_editing(temp_buffer_t *buffer, cursor_t *cursor,
    reading_char_type_t char_type)
{
    clear_input(buffer, cursor);
    if (char_type.type == ARROW_CHAR) {
        cursor_shifting(buffer, cursor, char_type.c);
    } else {
        buffer_back_editing(buffer, cursor, char_type.c);
    }
    display_input(buffer, cursor);
}
