/*
** EPITECH PROJECT, 2024
** Shell
** File description:
** get_input.c
*/

#include "../include/reading.h"

#include <stdio.h>

static void input_is_arrow(reading_char_type_t *char_type)
{
    char c_quote = 0;

    if (char_type->c == 27) {
        c_quote = getchar();
        if (c_quote == '[') {
            char_type->type = ARROW_CHAR;
            char_type->c = getchar();
        }
    }
}

reading_char_type_t get_input(void)
{
    reading_char_type_t char_type = {0};

    char_type.c = getchar();
    input_is_arrow(&char_type);
    return char_type;
}
