// Written by pseudomuto, a random guy on the web

#ifndef STACK_H
#define STACK_H

#include "linked_list.h"
#include "utils.h"

typedef struct {
    list *list;
} stack;

int stack_size(stack *s);
void stack_new(stack *s, int elementSize, freeFunction freeFn);
void stack_destroy(stack *s);
void stack_push(stack *s, void *element);
void stack_pop(stack *s, void *element);
void stack_peek(stack *s, void *element);
bool stack_empty(stack* s);

#endif