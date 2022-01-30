#include <stdio.h>
#include <stdlib.h>

#define BRACKETS_DIFF '}' - '{'
#define PARANTHESIS_DIFF ')' - '('
#define PERIODIC_DIFF ']' - '['

typedef struct Stack
{
    int size;
    int top;
    char *s;
} Stack;

void stack_create(Stack *st, int size)
{
    st->size = size;
    st->s = (char *)calloc(st->size, sizeof(char));
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

int stack_push(Stack *s, char key)
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

char stack_pop(Stack *s)
{
    if (stack_is_empty(*s))
    {
        printf("Warning: Stack Underflow.\n");
        return -1;
    }

    char x = s->s[s->top];

    s->s[s->top] = 0;
    s->top -= 1;

    return x;
}

int paranthesis_is_balance(char *exp, int size)
{
    Stack st;
    stack_create(&st, size);
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            stack_push(&st, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (stack_is_empty(st))
            {
                free(st.s);
                return 0;
            }
            char x = stack_pop(&st);
            if (exp[i] == ')')
            {
                x += PARANTHESIS_DIFF;
            }
            else if (exp[i] == ']')
            {
                x += PERIODIC_DIFF;
            }
            else if (exp[i] == '}')
            {
                x += BRACKETS_DIFF;
            }

            if (x != exp[i])
            {
                free(st.s);
                return 0;
            }
        }
    }

    if (stack_is_empty(st))
    {
        free(st.s);
        return 1;
    }

    free(st.s);
    return 0;
}

int main()
{
    char exp[] = "{([a+b] * [c-d]) / e}";
    printf("%s\n", paranthesis_is_balance(exp, sizeof(exp)) ? "Paranthesis are balanced" : "Paranthesis are not balanced");
    return 0;
}