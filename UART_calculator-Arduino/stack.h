/* Written by Stanimir Bogdanov */

#ifndef STACK_H
#define STACK_H

#include "utils.h"

#define STACK_BUFFER_SIZE 1024

typedef struct {
	char buff[STACK_BUFFER_SIZE];
	int elementSize;
	int size;
} stack;

typedef void (*freeFunction)(void *);

int stack_size(stack *s);
void stack_new(stack *s, int elementSize);
void stack_push(stack *s, void *element);
void stack_pop(stack *s, void *element);
void stack_peek(stack *s, void *element);
bool_t stack_empty(stack* s);

#endif
