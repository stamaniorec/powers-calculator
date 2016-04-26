#include <stdlib.h>
#include <assert.h>

#include "stack.h"
#include "utils.h"

int stack_size(stack *s)
{
    return s->size;
}

void stack_new(stack *s, int elementSize)
{
    s->elementSize = elementSize;
    s->size = 0;
}

#include <string.h>

void stack_push(stack *s, void *element)
{
    char* p = s->buff + s->size*s->elementSize;
    memcpy(p, element, s->elementSize);
    s->size = s->size + 1;
}

void stack_pop(stack *s, void *element)
{
    char* p;
    /* don't pop an empty stack! */
    assert(stack_size(s) > 0);
    p = s->buff + (s->size-1)*s->elementSize;
    memcpy(element, p, s->elementSize);
    s->size = s->size - 1;
}

void stack_peek(stack *s, void *element)
{
    char* p;
    assert(stack_size(s) > 0);
    p = s->buff + (s->size-1)*s->elementSize;
    memcpy(element, p, s->elementSize);
}

bool_t stack_empty(stack* s) {
    return stack_size(s) == 0;
}
