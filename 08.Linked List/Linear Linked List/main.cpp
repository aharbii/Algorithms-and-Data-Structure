#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *first;

public:
    LinkedList() { first = NULL; };
    LinkedList(int *array_ptr, int size);
    ~LinkedList();

    void display();
    void insert_node(int key, int index);
    int delete_node(int index);
    int count_nodes();
};

Node *first = NULL;
Node *second = NULL;
Node *third = NULL;

LinkedList::LinkedList(int *array_ptr, int size)
{
    if (size == 0)
    {
        return;
    }

    first = new Node;
    first->data = array_ptr[0];
    first->next = NULL;
    Node *t = NULL;
    Node *last = first;

    for (int i = 1; i < size; i++)
    {
        t = new Node;
        t->data = array_ptr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

LinkedList::~LinkedList()
{
    Node *p = first;
    while (first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}

void LinkedList::display()
{
    /* time --> space */
    /* O(n) --> O(1) */
    Node *p = first;
    if (p == NULL)
    {
        return;
    }

    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int LinkedList::count_nodes()
{
    /* O(n) */
    Node *p = first;
    int count = 0;
    while (p != NULL)
    {
        count += 1;
        p = p->next;
    }
    return count;
}

void LinkedList::insert_node(int key, int index)
{
    /* O(n) */
    Node *p = first;
    Node *t = first;

    if ((index < 0) || (index > count_nodes()))
    {
        return;
    }

    t = new Node;
    t->data = key;
    t->next = NULL;

    if (index == 0)
    {
        t->next = first;
        first = t;
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

int LinkedList::delete_node(int index)
{
    /* O(n) */
    if ((index < 1) || (index > count_nodes()))
    {
        return -1;
    }
    Node *p = NULL;
    Node *q = NULL;
    int x = 0;
    if (index == 1)
    {
        p = first;
        first = first->next;
        x = p->data;
        delete p;
    }
    else
    {
        p = first;
        for (int i = 1; i < index; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    LinkedList l(A, 5);
    l.display();
    l.insert_node(10, 3);
    l.display();

    return 0;
}