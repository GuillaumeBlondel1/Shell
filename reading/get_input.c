/*
** EPITECH PROJECT, 2024
** Shell
** File description:
** get_input.c
*/

#include "../include/reading.h"

#include <unistd.h>

static int input_is_editing(reading_char_type_t *char_type)
{
    switch (char_type->c) {
        case 1:
            char_type->type = START_HEAD;
            return 1;
        case 4:
            char_type->type = END_TRANSMISSION;
            return 1;
        case 5:
            char_type->type = ENQUERY;
            return 1;
        case 2:
            char_type->type = BACKWARD;
            return 1;
        case 6:
            char_type->type = FORWARD;
            return 1;
    }
    return 0;
}

static int input_is_supp(reading_char_type_t *char_type, char c_next)
{
    char c_tilde = 0;

    if (c_next == '3') {
        read(0, &c_tilde, 1);
        if (c_tilde == 126) {
            char_type->type = SUPP_CHAR;
            char_type->c = 0;
            return 1;
        }
    }
    return 0;
}

static int input_is_arrow(reading_char_type_t *char_type, char c_next)
{
    for (int i = 0; arrow_keys[i] != '\0'; i++) {
        if (c_next == arrow_keys[i]) {
            char_type->type = ARROW_CHAR;
            char_type->c = arrow_keys[i];
            return 1;
        }
    }
    return 0;
}

static int input_ctrl_reference(reading_char_type_t *char_type)
{
    char c_quote = 0;
    char c_next = 0;

    if (char_type->c == 27) {
        read(0, &c_quote, 1);
        if (c_quote == '[') {
            read(0, &c_next, 1);
            if (input_is_arrow(char_type, c_next)) {
                return 1;
            }
            if (input_is_supp(char_type, c_next)) {
                return 1;
            }
        }
        char_type->type = CTRL_CHAR;
        char_type->c = 0;
        return 1;
    }
    return 0;
}

static int input_is_del(reading_char_type_t *char_type)
{
    if (char_type->c == 127) {
        char_type->type = DEL_CHAR;
        char_type->c = 0;
        return 1;
    }
    return 0;
}

reading_char_type_t get_input(void)
{
    reading_char_type_t char_type = {0};

    read(0, &char_type.c, 1);
    if (input_is_editing(&char_type)) {
        return char_type;
    }
    if (input_ctrl_reference(&char_type)) {
        return char_type;
    }
    if (input_is_del(&char_type)) {
        return char_type;
    }
    return char_type;
}
