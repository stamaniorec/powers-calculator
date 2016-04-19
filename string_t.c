#include <stdlib.h>
#include <string.h>

#include "string_t.h"

void init_string(string_t* string, char* initial_value) {
    int length = strlen(initial_value);
    string->length = length;

    int i = 0;
    while(initial_value[i] != '\0') {
        string->string[i] = initial_value[i];
        ++i;
    }
    string->string[i] = '\0';
}

void append(string_t* string, char* value) {
    string->length = string->length + strlen(value);
    strcat(string->string, value);
}

void prepend(string_t* string, char* value) {
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
{}