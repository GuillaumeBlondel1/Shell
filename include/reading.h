/*
** EPITECH PROJECT, 2024
** Shell
** File description:
** reading.h
*/

#ifndef __READING__
    #define __READING__

    #define APPEND 1
    #define DEL 2
    #define SUPP 3

typedef struct temp_buffer_s {
    char *raw_buffer;
    int size_raw_buffer;
} temp_buffer_t;

typedef struct cursor_s {
    int front_cursor;
    int back_cursor;
} cursor_t;

enum char_type {
    SIMPLE_CHAR,
    ARROW_CHAR
};

typedef struct reading_char_type_s {
    enum char_type type;
    char c;
} reading_char_type_t;

char *reading_terminal(void);

void set_terminal_mode(void);
void unset_terminal_mode(void);

reading_char_type_t get_input(void);

void buffering_allocation(temp_buffer_t *current_buffer, char c, cursor_t *cursor, int macro);

#endif
