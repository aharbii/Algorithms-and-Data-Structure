#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *previous;
    int data;
    struct Node *next;
} Node;

Node *first = NULL;

void create(int *array_ptr, int size)
{
    /* O(n) */
    Node *t = NULL;
    Node *last = NULL;

    first = (Node *)malloc(sizeof(Node));
    first->data = array_ptr[0];
    first->previous = NULL;
    first->next = NULL;

    last = first;
    for (int i = 1; i < size; i++)
    {
        t = (Node *)malloc(sizeof(Node));
        t->data = array_ptr[i];
        t->next = last->next;
        t->previous = last;
        last->next = t;
        last = t;
    }
}

void display(Node *t)
{
    /* O(n) */
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int count_nodes(Node *t)
{
    /* O(n) */
    int count = 1;
    while (t->next != NULL)
    {
        count++;
        t = t->next;
    }
    return count;
}

void insert(Node *p, int key, int index)
{
    /* O(n) */
    if (index < 0 || index > count_nodes(p))
    {
        return;
    }

    Node *t = (Node *)malloc(sizeof(Node));
    t->data = key;
    t->previous = NULL;
    t->next = NULL;

    if (index == 0)
    {
        t->next = first;
        first->previous = t;
        first = t;
    }
    else
    {
        for (int i = 1; i < index; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        t->previous = p;
        if (p->next != NULL)
        {
            p->next->previous = t;
        }
        p->next = t;
    }
}

int delete_node(Node *p, int index)
{
    /* O(n) */
    if (index < 1 || index > count_nodes(first))
    {
        return -1;
    }

    int x = 0;
    if (index == 1)
    {
        first = first->next;
        if (first != NULL)
        {
            first->previous = NULL;
        }
        x = p->data;
        free(p);
    }
    else
    {
        for (int i = 1; i < index; i++)
        {
            p = p->next;
        }
        p->previous->next = p->next;
        if (p->next != NULL)
        {
            p->next->previous = p->previous;
        }
        x = p->data;
        free(p);
    }
    return x;
}

void reverse(Node *p)
{
    Node *temp = NULL;
    while (p != NULL)
    {
        temp = p->next;
        p->next = p->previous;
        p->previous = temp;
        p = p->previous;
        if ((p != NULL) && (p->next == NULL))
        {
            first = p;
        }
    }
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    create(A, 5);
    reverse(first);
    display(first);
    return 0;
}