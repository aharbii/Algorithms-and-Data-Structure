#ifndef CHAINS_H
#define CHAINS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *linear_search(Node *p, int key)
{
    /* O(n) */
    while (p != NULL)
    {
        if (p->data == key)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void insert_sorted(Node **H, int key)
{
    /* O(n) */
    Node *t = (Node *)malloc(sizeof(Node));
    t->data = key;
    t->next = NULL;

    if (*H == NULL)
    {
        *H = t;
    }
    else
    {
        Node *q = NULL;
        Node *p = *H;
        while ((p != NULL) && (p->data < key))
        {
            q = p;
            p = p->next;
        }
        if (p == *H)
        {
            t->next = *H;
            *H = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

#endif