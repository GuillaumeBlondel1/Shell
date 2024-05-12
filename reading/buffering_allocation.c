/*
** EPITECH PROJECT, 2024
** Shell
** File description:
** buffering_allocation.c
*/

#include "../include/reading.h"

#include <stdlib.h>
#include <string.h>

static void append_char(temp_buffer_t *current_buffer, char c, cursor_t *cursor)
{
    char *temp_buffer = NULL;

    current_buffer->size_raw_buffer++;
    temp_buffer = calloc((current_buffer->size_raw_buffer + 1) * sizeof(char),
        (current_buffer->size_raw_buffer + 1) * sizeof(char));
    for (int i = 0; i < cursor->back_cursor; i++) {
        temp_buffer[i] = current_buffer->raw_buffer[i];
    }
    temp_buffer[cursor->back_cursor] = c;
    if (cursor->front_cursor != current_buffer->size_raw_buffer) {
        temp_buffer = strcat(temp_buffer,
            &current_buffer->raw_buffer[cursor->back_cursor]);
    }
    free(current_buffer->raw_buffer);
    current_buffer->raw_buffer = temp_buffer;
    cursor->front_cursor++;
    cursor->back_cursor++;
}

static void delete_char(temp_buffer_t *current_buffer, cursor_t *cursor)
{
    char *temp_buffer = NULL;
    int j = 0;

    current_buffer->size_raw_buffer--;
    temp_buffer = calloc((current_buffer->size_raw_buffer + 1) * sizeof(char),
        (current_buffer->size_raw_buffer + 1) * sizeof(char));
    for (int i = 0; current_buffer->raw_buffer[i] != '\0'; i++) {
        if (i == (cursor->back_cursor - 1)) {
            continue;
        }
        temp_buffer[j] = current_buffer->raw_buffer[i];
        j++;
    }
    free(current_buffer->raw_buffer);
    current_buffer->raw_buffer = temp_buffer;
    if (cursor->back_cursor == 0 && cursor->front_cursor == 1) {
        return;
    }
    cursor->front_cursor--;
    cursor->back_cursor--;
}

static void supp_char(temp_buffer_t *current_buffer, cursor_t *cursor)
{
    char *temp_buffer = NULL;
    int j = 0;

    current_buffer->size_raw_buffer--;
    temp_buffer = calloc((current_buffer->size_raw_buffer + 1) * sizeof(char),
        (current_buffer->size_raw_buffer + 1) * sizeof(char));
    for (int i = 0; current_buffer->raw_buffer[i] != '\0'; i++) {
        if (i == cursor->back_cursor) {
            continue;
        }
        temp_buffer[j] = current_buffer->raw_buffer[i];
        j++;
    }
    free(current_buffer->raw_buffer);
    current_buffer->raw_buffer = temp_buffer;
}

void buffering_allocation(temp_buffer_t *current_buffer, char c, cursor_t *cursor, int macro)
{
    switch (macro) {
        case APPEND:
            append_char(current_buffer, c, cursor);
            break;
        case DEL:
            delete_char(current_buffer, cursor);
            break;
        case SUPP:
            supp_char(current_buffer, cursor);
            break;
        default:
            return;
    }
}
