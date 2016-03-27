// Written by Stanimir Bogdanov

#ifndef STRING_T_H
#define STRING_T_H

typedef struct {
    int length;
    int capacity;
    char* string;
} string_t;

void init_string(string_t* string, char* initial_value);
void resize_if_needed(string_t* string, char* value);
void append(string_t* string, char* value);
void prepend(string_t* string, char* value);
void destroy_string(string_t* string);

#endif