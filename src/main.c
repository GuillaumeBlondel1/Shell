/*
** EPITECH PROJECT, 2024
** Shell
** File description:
** main.c
*/

#include "../include/prompt.h"
#include "../include/reading.h"

#include <stdbool.h>

int main(int, char **, char **env)
{
    while (true) {
        display_prompt();
        reading_terminal();
    }
    return 0;
}
