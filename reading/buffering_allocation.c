/*
** EPITECH PROJECT, 2024
** Shell
** File description:
** buffering_allocation.c
*/

#include "../include/reading.h"

#include <stdlib.h>
#include <string.h>

static void append_char(temp_buffer_t *buffer, char c, cursor_t *cursor)
{
    char *temp_buffer = NULL;

    buffer->size_raw_buffer++;
    temp_buffer = calloc((buffer->size_raw_buffer + 1) * sizeof(char),
        (buffer->size_raw_buffer + 1) * sizeof(char));
    for (int i = 0; i < cursor->back_cursor; i++) {
        temp_buffer[i] = buffer->raw_buffer[i];
    }
    temp_buffer[cursor->back_cursor] = c;
    if (cursor->front_cursor != buffer->size_raw_buffer) {
        temp_buffer = strcat(temp_buffer,
            &buffer->raw_buffer[cursor->back_cursor]);
    }
    free(buffer->raw_buffer);
    buffer->raw_buffer = temp_buffer;
    cursor->front_cursor++;
    cursor->back_cursor++;
}

static void delete_char(temp_buffer_t *buffer, cursor_t *cursor)
{
    char *temp_buffer = NULL;
    int j = 0;

    if (buffer->size_raw_buffer == 0  || cursor->back_cursor == 0) {
        return;
    }
    buffer->size_raw_buffer--;
    temp_buffer = calloc((buffer->size_raw_buffer + 1) * sizeof(char),
        (buffer->size_raw_buffer + 1) * sizeof(char));
    for (int i = 0; buffer->raw_buffer[i] != '\0'; i++) {
        if (i == (cursor->back_cursor - 1)) {
            continue;
        }
        temp_buffer[j] = buffer->raw_buffer[i];
        j++;
    }
    free(buffer->raw_buffer);
    buffer->raw_buffer = temp_buffer;
    if (cursor->back_cursor == 0 && cursor->front_cursor == 1) {
        return;
    }
    cursor->front_cursor--;
    cursor->back_cursor--;
}

static void supp_char(temp_buffer_t *buffer, cursor_t *cursor)
{
    char *temp_buffer = NULL;
    int j = 0;

    if (buffer->size_raw_buffer == 0 ||
        cursor->back_cursor == buffer->size_raw_buffer) {
        return;
    }
    buffer->size_raw_buffer--;
    temp_buffer = calloc((buffer->size_raw_buffer + 1) * sizeof(char),
        (buffer->size_raw_buffer + 1) * sizeof(char));
    for (int i = 0; buffer->raw_buffer[i] != '\0'; i++) {
        if (i == cursor->back_cursor) {
            continue;
        }
        temp_buffer[j] = buffer->raw_buffer[i];
        j++;
    }
    free(buffer->raw_buffer);
    buffer->raw_buffer = temp_buffer;
}

void buffering_allocation(temp_buffer_t *buffer, char c, cursor_t *cursor, int macro)
{
    if (buffer->raw_buffer == NULL) {
        buffer->raw_buffer = strdup("");
    }
    switch (macro) {
        case APPEND:
            append_char(buffer, c, cursor);
            break;
        case DEL:
            delete_char(buffer, cursor);
            break;
        case SUPP:
            supp_char(buffer, cursor);
            break;
        default:
            return;
    }
}
