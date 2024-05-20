/*
** EPITECH PROJECT, 2024
** Shell
** File description:
** utils.c
*/

#include "../include/reading.h"

#include <string.h>

int length_save_buffer(temp_buffer_t *buffer,
    cursor_t *cursor, int setting)
{
    int length = 0;

    if (buffer->size_raw_buffer == 0) {
        return length;
    }
    if (setting == 0) {
        for (int i = 0; i < cursor->back_cursor; i++) {
            length++;
        }
    } else {
        for (int i = cursor->back_cursor; buffer->raw_buffer[i] != '\0'; i++) {
            length++;
        }
    }
    return length;
}

int length_temp_buffer(temp_buffer_t *buffer,
    cursor_t *cursor, int setting)
{
    int length = 0;

    if (buffer->size_raw_buffer == 0) {
        return length;
    }
    if (setting == 0) {
        for (int i = cursor->back_cursor; buffer->raw_buffer[i] != '\0'; i++) {
            length++;
        }
    } else {
        for (int i = 0; i < cursor->back_cursor; i++) {
            length++;
        }
    }
    return length;
}

void fill_save_buffer(temp_buffer_t *buffer, cursor_t *cursor, int setting)
{
    int j = 0;

    if (setting == 0) {
        for (int i = 0; i < cursor->back_cursor; i++) {
            buffer->save_buffer[j] = buffer->raw_buffer[i];
            j++;
        }
    } else {
        for (int i = cursor->back_cursor; buffer->raw_buffer[i] != '\0'; i++) {
            buffer->save_buffer[j] = buffer->raw_buffer[i];
            j++;
        }
    }
}

void fill_temp_buffer(char *temp_buffer, temp_buffer_t *buffer,
    cursor_t *cursor, int setting)
{
    int j = 0;

    if (setting == 0) {
        for (int i = cursor->back_cursor; buffer->raw_buffer[i] != '\0'; i++) {
            temp_buffer[j] = buffer->raw_buffer[i];
            j++;
        }
    } else {
        for (int i = 0; i < cursor->back_cursor; i++) {
            temp_buffer[j] = buffer->raw_buffer[i];
            j++;
        }
    }
}
