/*
** EPITECH PROJECT, 2024
** Shell
** File description:
** buffer_editing.c
*/

#include "../include/reading.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void editing_end_transmission(temp_buffer_t *buffer, cursor_t *cursor)
{
    if (buffer->size_raw_buffer == 0) {
        printf("\n");
        exit(0);
    }
    buffering_allocation(buffer, 0, cursor, SUPP);
}

void editing_cut_before_cursor(temp_buffer_t *buffer, cursor_t *cursor)
{
    char *temp_buffer = NULL;
    int length = 0;

    length = length_save_buffer(buffer, cursor, 0);
    if (length == 0) {
        return;
    }
    if (buffer->save_buffer != NULL) {
        free(buffer->save_buffer);
        buffer->save_buffer = NULL;
    }
    buffer->save_buffer = calloc((length + 1) * sizeof(char),
        (length + 1) * sizeof(char));
    fill_save_buffer(buffer, cursor, 0);
    length = length_temp_buffer(buffer, cursor, 0);
    temp_buffer = calloc((length + 1) * sizeof(char), (length + 1) * sizeof(char));
    fill_temp_buffer(temp_buffer, buffer, cursor, 0);
    free(buffer->raw_buffer);
    buffer->raw_buffer = temp_buffer;
    buffer->size_raw_buffer = strlen(buffer->raw_buffer);
    cursor->back_cursor = 0;
    cursor->front_cursor = 1;
}

void editing_cut_after_cursor(temp_buffer_t *buffer, cursor_t *cursor)
{
    char *temp_buffer = NULL;
    int length = 0;

    length = length_save_buffer(buffer, cursor, 1);
    if (length == 0) {
        return;
    }
    if (buffer->save_buffer != NULL) {
        free(buffer->save_buffer);
        buffer->save_buffer = NULL;
    }
    buffer->save_buffer = calloc((length + 1) * sizeof(char),
        (length + 1) * sizeof(char));
    fill_save_buffer(buffer, cursor, 1);
    length = length_temp_buffer(buffer, cursor, 1);
    temp_buffer = calloc((length + 1) * sizeof(char), (length + 1) * sizeof(char));
    fill_temp_buffer(temp_buffer, buffer, cursor, 1);
    free(buffer->raw_buffer);
    buffer->raw_buffer = temp_buffer;
    buffer->size_raw_buffer = strlen(buffer->raw_buffer);
    cursor->back_cursor = buffer->size_raw_buffer;
    cursor->front_cursor = cursor->back_cursor + 1;
}

void editing_copy_buffer(temp_buffer_t *buffer, cursor_t *cursor)
{
    char *temp_buffer = NULL;
    int length_buffer = 0;
    int j = 0;

    if (buffer->save_buffer == NULL) {
        return;
    }
    length_buffer += buffer->size_raw_buffer;
    length_buffer += strlen(buffer->save_buffer);
    temp_buffer = calloc((length_buffer + 1) * sizeof(char),
        (length_buffer + 1) * sizeof(char));
    for (int i = 0; i < cursor->back_cursor; i++) {
        temp_buffer[j] = buffer->raw_buffer[i];
        j++;
    }
    for (int i = 0; buffer->save_buffer[i] != '\0'; i++) {
        temp_buffer[j] = buffer->save_buffer[i];
        j++;
    }
    if (buffer->raw_buffer != NULL) {
        temp_buffer = strcat(temp_buffer,
            &buffer->raw_buffer[cursor->back_cursor]);
    }
    free(buffer->raw_buffer);
    buffer->raw_buffer = temp_buffer;
    buffer->size_raw_buffer = length_buffer;
    cursor->back_cursor = j;
    cursor->front_cursor = cursor->back_cursor + 1;
}
