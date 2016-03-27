#include <stdlib.h>
#include <assert.h>

#include "stack.h"
#include "utils.h"

int stack_size(stack *s)
{
    return list_size(s->list);
}

void stack_new(stack *s, int elementSize, freeFunction freeFn)
{
    s->list = malloc(sizeof(list));
    // make sure the malloc call didn't fail...
    assert(s->list != NULL);

    list_new(s->list, elementSize, freeFn);
}

void stack_destroy(stack *s)
{
    list_destroy(s->list);
    free(s->list);
}

void stack_push(stack *s, void *element)
{
    list_prepend(s->list, element);
}

void stack_pop(stack *s, void *element)
{
    // don't pop an empty stack!
    assert(stack_size(s) > 0);

    list_head(s->list, element, TRUE);
}

void stack_peek(stack *s, void *element)
{
    assert(stack_size(s) > 0);
    list_head(s->list, element, FALSE);
}

bool stack_empty(stack* s) {
    return stack_size(s) == 0;
}