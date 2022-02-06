#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

class Node
{
public:
    Node *left_child;
    int data;
    Node *right_child;
};

class Queue
{
private:
    int front;
    int rear;
    int size;
    Node **elements;

public:
    Queue(int size_val);
    void display();
    int enqueue(Node *key);
    Node *dequeue();
    int is_empty();
    int is_full();
    ~Queue();
};

Queue::Queue(int size_val)
    : size{size_val}, front{-1}, rear{-1}
{
    elements = new Node *[size];
}

Queue::~Queue()
{
    delete[] elements;
}

void Queue::display()
{
    for (int i = (front + 1); i <= rear; i++)
    {
        cout << elements[i] << " ";
    }
    cout << endl;
}

int Queue::is_empty()
{
    if (front == rear)
    {
        return 1;
    }
    return 0;
}

int Queue::is_full()
{
    if ((rear + 1) == size)
    {
        return 1;
    }
    return 0;
}

int Queue::enqueue(Node *key)
{
    if (is_full())
    {
        cout << "Queue Overflow." << endl;
        return 0;
    }

    rear += 1;
    elements[rear] = key;
    return 1;
}

Node *Queue::dequeue()
{
    if (is_empty())
    {
        cout << "Queue Underflow." << endl;
        return NULL;
    }

    front += 1;
    Node *x = elements[front];
    elements[front] = 0;
    return x;
}

#endif