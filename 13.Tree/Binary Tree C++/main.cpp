#include <iostream>
#include "queue.h"

using namespace std;

class Tree
{
public:
    Node *root;
    Tree() { root = NULL; };
    void create_tree();
    void preorder(Node *p);
    void postorder(Node *p);
    void inorder(Node *p);
    void level_order(Node *root);
    int height(Node *root);
};

void Tree::create_tree()
{
    Queue q(100);
    int value;
    cout << "Enter root value: ";
    cin >> value;
    root = new Node;
    root->data = value;
    root->left_child = NULL;
    root->right_child = NULL;
    q.enqueue(root);
    while (!q.is_empty())
    {
        Node *p = q.dequeue();
        cout << "Enter " << p->data << " left child: ";
        cin >> value;
        if (value != -1)
        {
            Node *t = new Node;
            t->data = value;
            t->left_child = NULL;
            t->right_child = NULL;
            p->left_child = t;
            q.enqueue(t);
        }
        cout << "Enter " << p->data << " right child: ";
        cin >> value;
        if (value != -1)
        {
            Node *t = new Node;
            t->data = value;
            t->left_child = NULL;
            t->right_child = NULL;
            p->right_child = t;
            q.enqueue(t);
        }
    }
}

void Tree::preorder(Node *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        preorder(p->left_child);
        preorder(p->right_child);
    }
}

void Tree::inorder(Node *p)
{
    if (p != NULL)
    {
        inorder(p->left_child);
        cout << p->data << " ";
        inorder(p->right_child);
    }
}

void Tree::postorder(Node *p)
{
    if (p != NULL)
    {
        postorder(p->left_child);
        postorder(p->right_child);
        cout << p->data << " ";
    }
}

void Tree::level_order(Node *root)
{
    Queue q(100);
    cout << root->data << " ";
    q.enqueue(root);

    while (!q.is_empty())
    {
        root = q.dequeue();
        if (root->left_child != NULL)
        {
            cout << root->left_child->data << " ";
            q.enqueue(root->left_child);
        }
        if (root->right_child != NULL)
        {
            cout << root->right_child->data << " ";
            q.enqueue(root->right_child);
        }
    }
}

int Tree::height(Node *root)
{
    int x = 0;
    int y = 0;
    if (root == NULL)
    {
        return 0;
    }
    x = height(root->left_child);
    y = height(root->right_child);
    if (x > y)
    {
        return x + 1;
    }
    else
    {
        return y + 1;
    }
}

int main()
{
    Tree t;
    t.create_tree();
    cout << "Preorder: ";
    t.preorder(t.root);
    cout << endl;
    cout << "Inorder:  ";
    t.inorder(t.root);
    cout << endl;
    return 0;
}