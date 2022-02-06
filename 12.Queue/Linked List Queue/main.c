#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

void display()
{
    Node *p = front;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int is_empty()
{
    if (front == NULL)
    {
        return 1;
    }
    return 0;
}

int is_full()
{
    Node *t = (Node *)malloc(sizeof(Node));
    if (t == NULL)
    {
        free(t);
        return 1;
    }

    free(t);
    return 0;
}

int enqueue(int key)
{
    if (is_full())
    {
        printf("Queue Overflow.\n");
        return 0;
    }

    Node *t = (Node *)malloc(sizeof(Node));
    t->data = key;
    t->next = NULL;
    if (is_empty())
    {
        front = t;
        rear = t;
    }
    else
    {
        rear->next = t;
        rear = t;
    }
    return 1;
}

int dequeue()
{
    if (is_empty())
    {
        printf("Queue Underflow.\n");
        return 0;
    }

    Node *p = front;
    front = front->next;
    int x = p->data;
    free(p);
    return x;
}

int main()
{
    dequeue();

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    printf("%d\n", dequeue());

    return 0;
}