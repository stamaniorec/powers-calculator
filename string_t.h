/* Written by Stanimir Bogdanov */

#ifndef STRING_T_H
#define STRING_T_H

#define BUFFER_SIZE 512

typedef struct {
    int length;
    char string[BUFFER_SIZE];
} string_t;

void init_string(string_t* string, char* initial_value);
void resize_if_needed(string_t* string, char* value);
void append(string_t* string, char* value);
void prepend(string_t* string, char* value);

#endif