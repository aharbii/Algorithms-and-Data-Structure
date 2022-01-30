#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int size;
    int top;
    char *s;
} Stack;

int is_operand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')' || x == '^')
    {
        return 0;
    }
    return 1;
}

int get_precedence_outside(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }

    if (x == '*' || x == '/')
    {
        return 3;
    }

    if (x == '^')
    {
        return 6;
    }

    if (x == '(')
    {
        return 7;
    }

    if (x == ')')
    {
        return 0;
    }

    return -1;
}

int get_precedence_inside(char x)
{
    if (x == '+' || x == '-')
    {
        return 2;
    }

    if (x == '*' || x == '/')
    {
        return 4;
    }

    if (x == '^')
    {
        return 5;
    }

    if (x == '(')
    {
        return 0;
    }

    return -1;
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

int stack_top(Stack s)
{
    if (stack_is_empty(s))
    {
        return -1;
    }

    return s.s[s.top];
}

void infix_to_postfix(char *infix, int infix_size, char *postfix)
{
    Stack st;
    st.size = infix_size;
    st.s = (char *)calloc(infix_size, sizeof(char));
    st.top = -1;
    int j = 0;
    int i = 0;
    while (infix[i] != '\0')
    {
        if (is_operand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (get_precedence_outside(infix[i]) > get_precedence_inside(stack_top(st)))
            {
                stack_push(&st, infix[i++]);
            }
            else if (get_precedence_outside(infix[i]) == get_precedence_inside(stack_top(st)))
            {
                stack_pop(&st);
            }
            else
            {
                postfix[j++] = stack_pop(&st);
            }
        }
    }

    while (!stack_is_empty(st))
    {
        char x = stack_pop(&st);
        postfix[j++] = get_precedence_inside(x) ? x : '\0';
    }

    postfix[j] = '\0';
}

int main()
{
    char infix[] = "((a+b)*c)-d^e^f";
    int infix_size = sizeof(infix);
    char postfix[100] = {0};
    infix_to_postfix(infix, infix_size, postfix);
    printf("%s\n", postfix);
    return 0;
}
