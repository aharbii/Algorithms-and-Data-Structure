#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int front;
    int rear;
    int size;
    int *elements;
} Queue;

void queue_create(Queue *q, int size)
{
    q->size = size;
    q->front = -1;
    q->rear = -1;
    q->elements = (int *)calloc(size, sizeof(int));
}

void queue_display(Queue q)
{
    for (int i = (q.front + 1); i <= q.rear; i++)
    {
        printf("%d ", q.elements[i]);
    }
    printf("\n");
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

int enqueue(Queue *q, int key)
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

int dequeue(Queue *q)
{
    if (queue_is_empty(*q))
    {
        printf("Queue Underflow.\n");
        return -1;
    }

    q->front += 1;
    int x = q->elements[q->front];
    q->elements[q->front] = 0;
    return x;
}

void breadth_first_search(int i, int n, int A[][7])
{
    int *visited = (int *)calloc(n + 1, sizeof(int));
    Queue q;
    queue_create(&q, 8);
    printf("%d ", i);
    visited[i] = 1;
    enqueue(&q, i);
    while (!queue_is_empty(q))
    {
        int u = dequeue(&q);
        for (int v = 1; v < n; v++)
        {
            if (A[u][v] && !visited[v])
            {
                printf("%d ", v);
                visited[v] = 1;
                enqueue(&q, v);
            }
        }
    }
    printf("\n");
}

int main()
{
    int A[][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};
    breadth_first_search(4, 7, A);
    return 0;
}