#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

void create(int *array_ptr, int size)
{
    /* O(n) */
    Node *t;
    head = (Node *)malloc(sizeof(Node));
    head->data = array_ptr[0];
    head->next = head;
    Node *last = head;
    for (int i = 1; i < size; i++)
    {
        t = (Node *)malloc(sizeof(Node));
        t->data = array_ptr[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void display(Node *h)
{
    /* O(n) */
    if (h == NULL)
    {
        return;
    }

    do
    {
        printf("%d ", h->data);
        h = h->next;
    } while (h != head);
    printf("\n");
}

void display_recursive(Node *h)
{
    /* O(n) */
    static int flag = 0;
    if ((h != head) || (flag == 0))
    {
        flag = 1;
        printf("%d ", h->data);
        display_recursive(h->next);
    }
    flag = 0;
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

void insert_node(Node *p, int key, int index)
{
    /* O(n) */
    if (index < 0 || index > count_nodes(head))
    {
        return;
    }

    Node *t = (Node *)malloc(sizeof(Node));
    t->data = key;
    t->next = NULL;

    if (index == 0)
    {
        if (head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            t->next = head;
            Node *p = head;

            while (p->next != head)
            {
                p = p->next;
            }

            p->next = t;
            head = t;
        }
    }
    else
    {
        for (int i = 1; i < index; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

int delete_node(Node *p, int index)
{
    /* O(n) */
    if ((index < 1) || (index > count_nodes(p)))
    {
        return -1;
    }

    Node *q = NULL;
    int x = 0;
    if (index == 1)
    {
        q = head;
        while (p->next != head)
        {
            p = p->next;
        }
        x = head->data;
        if (p == head)
        {
            free(head);
            head = NULL;
        }
        else
        {
            p->next = q->next;
            head = head->next;
            free(q);
        }
    }
    else
    {
        for (int i = 1; i < index; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
    }
    return x;
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    create(A, 5);
    delete_node(head, 1);
    display(head);
    printf("%d\n", count_nodes(head));
    return 0;
}