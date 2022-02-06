#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int size;
    int top;
    int *s;
} Stack;

void stack_create(Stack *st)
{
    printf("Enter size of stack: ");
    scanf("%d", &st->size);
    st->s = (int *)calloc(st->size, sizeof(int));
    st->top = -1;
}

void stack_display(Stack s)
{
    for (int i = s.top; i >= 0; i--)
    {
        printf("%d ", s.s[i]);
    }
    printf("\n");
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

int stack_push(Stack *s, int key)
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

int stack_pop(Stack *s)
{
    if (stack_is_empty(*s))
    {
        printf("Warning: Stack Underflow.\n");
        return -1;
    }

    int x = s->s[s->top];

    s->s[s->top] = 0;
    s->top -= 1;

    return x;
}

int stack_peek(Stack s, int pos)
{
    int index = s.top - pos + 1;

    if (index < 0)
    {
        printf("Warning: Invalid Position.\n");
        return -1;
    }

    return s.s[index];
}

int stack_top(Stack s)
{
    if (stack_is_empty(s))
    {
        return -1;
    }

    return s.s[s.top];
}

int main()
{
    Stack st;

    stack_create(&st);

    stack_push(&st, 10);
    stack_push(&st, 20);
    stack_push(&st, 30);
    stack_push(&st, 40);
    // stack_push(&st, 50);

    printf("%d\n", stack_peek(st, 2));
    // printf("%d\n", stack_pop(&st));
    // printf("%d\n", stack_pop(&st));

    stack_display(st);

    free(st.s);

    return 0;
}