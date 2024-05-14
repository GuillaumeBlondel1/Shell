/*
** EPITECH PROJECT, 2024
** Shell
** File description:
** buffer_editing.c
*/

#include "../include/reading.h"

#include <stdlib.h>
#include <stdio.h>

void editing_end_transmission(temp_buffer_t *buffer, cursor_t *cursor)
{
    if (buffer->size_raw_buffer == 0) {
        printf("\n");
        exit(0);
    }
    buffering_allocation(buffer, 0, cursor, SUPP);
}
