#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *left_child;
    int data;
    struct Node *right_child;
} Node;


typedef struct Queue
{
    int front;
    int rear;
    int size;
    Node **elements;
} Queue;

void queue_create(Queue *q, int size)
{
    q->size = size;
    q->front = -1;
    q->rear = -1;
    q->elements = (Node **)calloc(size, sizeof(Node *));
}

int queue_is_empty(Queue q)
{
    if (q.front == q.rear)
    {
        return 1;
    }
    return 0;
}

int queue_is_full(Queue q)
{
    if ((q.rear + 1) == q.size)
    {
        return 1;
    }
    return 0;
}

int enqueue(Queue *q, Node *key)
{
    if (queue_is_full(*q))
    {
        printf("Queue Overflow.\n");
        return 0;
    }

    q->rear += 1;
    q->elements[q->rear] = key;
    return 1;
}

Node *dequeue(Queue *q)
{
    if (queue_is_empty(*q))
    {
        printf("Queue Underflow.\n");
        return NULL;
    }

    q->front += 1;
    Node *x = q->elements[q->front];
    q->elements[q->front] = 0;
    return x;
}

#endif