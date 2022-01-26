#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *previous;
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

void create(int *array_ptr, int size)
{
    /* O(n) */
    Node *t = NULL;
    Node *last = NULL;

    head = (Node *)malloc(sizeof(Node));
    head->data = array_ptr[0];
    head->previous = head;
    head->next = head;

    last = head;
    for (int i = 1; i < size; i++)
    {
        t = (Node *)malloc(sizeof(Node));
        t->data = array_ptr[i];
        t->next = last->next;
        t->previous = last;
        last->next = t;
        last = t;
    }
    head->previous = last;
}

void display(Node *t)
{
    /* O(n) */
    if (t == NULL)
    {
        return;
    }

    do
    {
        printf("%d ", t->data);
        t = t->next;
    } while (t != head);
    printf("\n");
}

int count_nodes(Node *p)
{
    /* O(n) */
    int count = 1;

    if (head == NULL)
    {
        return 0;
    }

    while (p->next != head)
    {
        count++;
        p = p->next;
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
        t->next = head;
        t->previous = head->previous;
        head->previous->next = t;
        head->previous = t;
        head = t;
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
    if (index < 1 || index > count_nodes(head))
    {
        return -1;
    }

    int x = 0;
    Node *q = NULL;
    if (index == 1)
    {
        if (head->next == head)
        {
            free(head);
            head = NULL;
        }
        else
        {
            q = head;
            head->next->previous = head->previous;
            head->previous->next = head->next;
            head = head->next;
            x = q->data;
            free(q);
        }
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

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    create(A, 5);
    reverse(head);
    display(head);
    return 0;
}