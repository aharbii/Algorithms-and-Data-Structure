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
    if (x == '+' || x == '-' || x == '*' || x == '/')
    {
        return 0;
    }
    return 1;
}

int get_precedence(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }

    if (x == '*' || x == '/')
    {
        return 2;
    }

    return 0;
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
            if (get_precedence(infix[i]) > get_precedence(stack_top(st)))
            {
                stack_push(&st, infix[i++]);
            }
            else
            {
                postfix[j++] = stack_pop(&st);
            }
        }
    }

    while (!stack_is_empty(st))
    {
        postfix[j++] = stack_pop(&st);
    }

    postfix[j] = '\0';
}

int postfix_evaluation(char *postfix, int postfix_size)
{
    Stack st;
    st.size = postfix_size;
    st.top = -1;
    st.s = (char *)calloc(st.size, sizeof(char));

    int operation = 1;
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (is_operand(postfix[i]))
        {
            stack_push(&st, postfix[i] - '0');
        }
        else
        {
            int b = stack_pop(&st);
            int a = stack_pop(&st);
            int current_operation = 1;
            if (postfix[i] == '+')
            {
                current_operation = a + b;
            }
            else if (postfix[i] == '-')
            {
                current_operation = a - b;
            }
            else if (postfix[i] == '*')
            {
                current_operation = a * b;
            }
            else
            {
                current_operation = a / b;
            }

            stack_push(&st, current_operation);
        }
    }

    operation = stack_pop(&st);
    return operation;
}

int main()
{
    char infix[] = "3*5+6/2-4";
    int infix_size = sizeof(infix);
    char postfix[100] = {0};
    infix_to_postfix(infix, infix_size, postfix);
    printf("%s\n", postfix);
    char *postfix2 = "234*+82/-";
    printf("%d\n", postfix_evaluation(postfix2, 10));
    return 0;
}
