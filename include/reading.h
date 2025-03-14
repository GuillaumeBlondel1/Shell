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

    #define MOVE_CURSOR_LEFT "\033[D\7"
    #define MOVE_CURSOR_RIGHT "\033[C\7"
    #define ERASE_CHAR "\b \b"

    #define KEY_LEFT 'D'
    #define KEY_RIGHT 'C'

typedef struct temp_buffer_s {
    char *raw_buffer;
    int size_raw_buffer;
    char *save_buffer;
} temp_buffer_t;

typedef struct cursor_s {
    int front_cursor;
    int back_cursor;
} cursor_t;

enum char_type {
    SIMPLE_CHAR,
    ARROW_CHAR,
    DEL_CHAR,
    SUPP_CHAR,
    CTRL_CHAR,
    START_HEAD,
    ENQUERY,
    END_TRANSMISSION,
    FORWARD,
    BACKWARD,
    CUT_BEFORE,
    CUT_AFTER,
    COPY,
    BACK_TO_LINE
};

static const char arrow_keys[] = "ABCD";

typedef struct reading_char_type_s {
    enum char_type type;
    char c;
} reading_char_type_t;

char *reading_terminal(void);

void set_terminal_mode(void);
void unset_terminal_mode(void);

reading_char_type_t get_input(void);

void buffering_allocation(temp_buffer_t *buffer, char c, cursor_t *cursor, int macro);

void line_editing(temp_buffer_t *buffer, cursor_t *cursor,
    reading_char_type_t char_type);

void cursor_shifting_backward(cursor_t *cursor);
void cursor_shifting_forward(temp_buffer_t *buffer, cursor_t *cursor);
void cursor_shifting(temp_buffer_t *buffer,
    cursor_t *cursor, char arrow_key);
void cursor_shifting_start_line(cursor_t *cursor);
void cursor_shifting_end_line(temp_buffer_t *buffer, cursor_t *cursor);

void editing_end_transmission(temp_buffer_t *buffer, cursor_t *cursor);
void editing_cut_before_cursor(temp_buffer_t *buffer, cursor_t *cursor);
void editing_cut_after_cursor(temp_buffer_t *buffer, cursor_t *cursor);

int length_save_buffer(temp_buffer_t *buffer,
    cursor_t *cursor, int setting);
int length_temp_buffer(temp_buffer_t *buffer,
    cursor_t *cursor, int setting);
void fill_save_buffer(temp_buffer_t *buffer, cursor_t *cursor, int setting);
void fill_temp_buffer(char *temp_buffer, temp_buffer_t *buffer,
    cursor_t *cursor, int setting);
void editing_copy_buffer(temp_buffer_t *buffer, cursor_t *cursor);

#endif
