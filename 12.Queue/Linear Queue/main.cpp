#include <iostream>

using namespace std;

class Queue
{
    private:
    int front;
    int rear;
    int size;
    int *elements;
    public:
    Queue(int size_val);
    void display();
    int enqueue(int key);
    int dequeue();
    int is_empty();
    int is_full();
    ~Queue();
};

Queue::Queue(int size_val)
:   size{size_val}, front{-1}, rear{-1}
{
    elements = new int[size];
}

Queue::~Queue()
{
    delete []elements;
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

int Queue::enqueue(int key)
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

int Queue::dequeue()
{
    if (is_empty())
    {
        cout << "Queue Underflow." << endl;
        return -1;
    }

    front += 1;
    int x = elements[front];
    elements[front] = 0;
    return x;
}

int main()
{
    int size = 5;
    Queue q(size);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    cout << q.dequeue() << endl;

    return 0;
}