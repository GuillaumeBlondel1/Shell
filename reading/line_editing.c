/*
** EPITECH PROJECT, 2024
** Shell
** File description:
** line_editing.c
*/

#include "../include/reading.h"

#include <stdio.h>

static void display_input(temp_buffer_t *buffer, cursor_t *cursor)
{
    if (buffer->raw_buffer != NULL) {
        printf("%s", buffer->raw_buffer);
        fflush(stdout);
    }
    for (int i = buffer->size_raw_buffer; i > cursor->back_cursor; i--) {
        printf(MOVE_CURSOR_LEFT);
        fflush(stdout);
    }
}

static void clear_input(temp_buffer_t *buffer, cursor_t *cursor)
{
    for (int i = cursor->back_cursor; i < buffer->size_raw_buffer; i++) {
        printf(MOVE_CURSOR_RIGHT);
        fflush(stdout);
    }
    for (int i = buffer->size_raw_buffer; i > 0; i--) {
        printf(ERASE_CHAR);
        fflush(stdout);
    }
}

static void buffer_back_editing(temp_buffer_t *buffer, cursor_t *cursor,
    reading_char_type_t char_type)
{
    switch (char_type.type) {
        case START_HEAD:
            cursor_shifting_start_line(cursor);
            break;
        case CTRL_CHAR:
            break;
        case DEL_CHAR:
            buffering_allocation(buffer, 0, cursor, DEL);
            break;
        case SUPP_CHAR:
            buffering_allocation(buffer, 0, cursor, SUPP);
            break;
        case END_TRANSMISSION:
            editing_end_transmission(buffer, cursor);
            break;
        default:
            buffering_allocation(buffer, char_type.c, cursor, APPEND);
            break;
    }
}

void line_editing(temp_buffer_t *buffer, cursor_t *cursor,
    reading_char_type_t char_type)
{
    clear_input(buffer, cursor);
    if (char_type.type == ARROW_CHAR) {
        cursor_shifting(buffer, cursor, char_type.c);
    } else {
        buffer_back_editing(buffer, cursor, char_type);
    }
    display_input(buffer, cursor);
}
