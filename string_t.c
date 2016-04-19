#include <stdlib.h>
#include <string.h>

#include "string_t.h"

void init_string(string_t* string, char* initial_value) {
    int length = strlen(initial_value);
    string->length = length;
    // string->capacity = length * 2;
    // string->string = malloc(sizeof(char) * length);


    int i;
    // make me better
    for(i = 0; i < length; ++i) {
        string->string[i] = initial_value[i];
    }
    string->string[length] = '\0';
}

// void resize_if_needed(string_t* string, char* value) {
//     int length = strlen(value);
//     int new_length = string->length + length;
//     if(string->capacity < new_length) {
//         int new_capacity = new_length * 2;
//         char* new_buffer = malloc(sizeof(char) * new_capacity);
//         strcpy(new_buffer, string->string);
//         free(string->string);
//         string->string = new_buffer;
//         string->capacity = new_capacity;
//     }
// }

void append(string_t* string, char* value) {
    // resize_if_needed(string, value);
    // int new_length = string->length + strlen(value);
    string->length = string->length + strlen(value); //new_length;
    strcat(string->string, value);
}

void prepend(string_t* string, char* value) {
    // resize_if_needed(string, value);
    int length = strlen(value);
    int i;
    for(i = string->length-1; i >= 0; --i) {
        string->string[i+length] = string->string[i];
    }
    for(i = 0; i < length; ++i) {
        string->string[i] = value[i];
    }
}

void destroy_string(string_t* string)
{
    // free(string->string);
}