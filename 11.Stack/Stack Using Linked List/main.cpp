#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack() { top = NULL; };
    void display();
    int is_empty();
    int is_full();
    int push(int key);
    int pop();
    int peak(int pos);
    int stack_top();
};

void Stack::display()
{
    cout << "Stack elements: ";
    Node *p = top;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int Stack::is_empty()
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

int Stack::is_full()
{
    Node *t = new Node;
    if (t == NULL)
    {
        delete t;
        return 0;
    }

    delete t;
    return 1;
}

int Stack::push(int key)
{
    Node *t = new Node;
    if (t == NULL)
    {
        cout << "Warning: Stack Overflow." << endl;
        return -1;
    }

    t->data = key;
    t->next = top;
    top = t;
    return 1;
}

int Stack::pop()
{
    if (is_empty())
    {
        cout << "Warning: Stack Underflow." << endl;
        return -1;
    }

    Node *p = top;
    top = top->next;
    int x = p->data;
    delete p;
    return x;
}

int Stack::peak(int pos)
{
    Node *p = top;
    int i = 1;
    while (p != NULL && i < pos)
    {
        p = p->next;
        i++;
    }

    if (p == NULL)
    {
        cout << "Warning: Invalid Position." << endl;
        return -1;
    }

    return p->data;
}

int Stack::stack_top()
{
    if (is_empty())
    {
        return -1;
    }

    return top->data;
}

int main()
{
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    st.display();

    cout << st.pop() << " has been deleted" << endl;
    st.display();

    cout << "second element is " << st.peak(2) << endl;
    cout << "top element is " << st.stack_top() << endl;

    cout << st.pop() << " has been deleted" << endl;
    cout << (st.is_empty() ? "Stack is empty" : "Stack is not empty") << endl;
    st.display();

    cout << st.pop() << " has been deleted" << endl;
    cout << (st.is_empty() ? "Stack is empty" : "Stack is not empty") << endl;
    st.display();

    cout << st.pop() << " has been deleted" << endl;
    cout << (st.is_empty() ? "Stack is empty" : "Stack is not empty") << endl;
    st.display();

    cout << st.pop() << " has been deleted" << endl;
    cout << (st.is_empty() ? "Stack is empty" : "Stack is not empty") << endl;
    st.display();

    cout << st.pop() << " has been deleted" << endl;
    cout << (st.is_empty() ? "Stack is empty" : "Stack is not empty") << endl;
    st.display();

    return 0;
}