#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct Stack
{
    int size;
    int top;
    Node **s;
} Stack;

void stack_create(Stack *st, int size)
{
    st->s = (Node **)calloc(st->size, sizeof(Node *));
    st->top = -1;
}

int stack_is_empty(Stack s)
{
    if (s.top == -1)
    {
        return 1;
    }

    return 0;
}

int stack_is_full(Stack s)
{
    return s.top == (s.size - 1);
}

int stack_push(Stack *s, Node *key)
{
    if (stack_is_full(*s))
    {
        printf("Warning: Stack Overflow.\n");
        return 0;
    }

    s->top += 1;
    s->s[s->top] = key;

    return 1;
}

Node *stack_pop(Stack *s)
{
    if (stack_is_empty(*s))
    {
        printf("Warning: Stack Underflow.\n");
        return NULL;
    }

    Node *x = s->s[s->top];

    s->s[s->top] = 0;
    s->top -= 1;

    return x;
}

#endif
