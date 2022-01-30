#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *top = NULL;

void stack_display()
{
    printf("Stack elements: ");
    Node *p = top;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int stack_is_empty()
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

int stack_is_full()
{
    Node *t = (Node *)malloc(sizeof(Node));
    if (t == NULL)
    {
        free(t);
        return 0;
    }

    free(t);
    return 1;
}

int stack_push(int key)
{
    Node *t = (Node *)malloc(sizeof(Node));
    if (t == NULL)
    {
        printf("Warning: Stack Overflow.\n");
        return -1;
    }

    t->data = key;
    t->next = top;
    top = t;
    return 1;
}

int stack_pop()
{
    if (stack_is_empty())
    {
        printf("Warning: Stack Underflow.\n");
        return -1;
    }

    Node *p = top;
    top = top->next;
    int x = p->data;
    free(p);
    return x;
}

int stack_peak(int pos)
{
    Node *p = top;
    int i = 1;
    while (p != NULL && i < pos)
    {
        p = p->next;
        i++;
    }

    if (p == NULL)
    {
        printf("Warning: Invalid Position.\n");
        return -1;
    }

    return p->data;
}

int stack_top()
{
    if (stack_is_empty())
    {
        return -1;
    }

    return top->data;
}

int main()
{
    stack_push(10);
    stack_push(20);
    stack_push(30);
    stack_push(40);
    stack_push(50);

    stack_display();

    printf("%d has been deleted\n", stack_pop());
    stack_display();

    printf("second element is %d\n", stack_peak(2));
    printf("top element is %d\n", stack_top());

    printf("%d has been deleted\n", stack_pop());
    printf("%s\n", stack_is_empty() ? "Stack is empty" : "Stack is not empty");
    stack_display();

    printf("%d has been deleted\n", stack_pop());
    printf("%s\n", stack_is_empty() ? "Stack is empty" : "Stack is not empty");
    stack_display();

    printf("%d has been deleted\n", stack_pop());
    printf("%s\n", stack_is_empty() ? "Stack is empty" : "Stack is not empty");
    stack_display();

    printf("%d has been deleted\n", stack_pop());
    printf("%s\n", stack_is_empty() ? "Stack is empty" : "Stack is not empty");
    stack_display();

    printf("%d has been deleted\n", stack_pop());
    printf("%s\n", stack_is_empty() ? "Stack is empty" : "Stack is not empty");
    stack_display();

    return 0;
}