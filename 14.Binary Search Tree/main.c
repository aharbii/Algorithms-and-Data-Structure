#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"

Node *root = NULL;

void create()
{
    Queue q;
    queue_create(&q, 100);
    int value;
    printf("Enter root value: ");
    scanf("%d", &value);
    root = (Node *)malloc(sizeof(Node));
    root->data = value;
    root->left_child = NULL;
    root->right_child = NULL;
    enqueue(&q, root);
    while (!queue_is_empty(q))
    {
        Node *p = dequeue(&q);
        printf("Enter %d left child: ", p->data);
        scanf("%d", &value);
        if (value != -1)
        {
            Node *t = (Node *)malloc(sizeof(Node));
            t->data = value;
            t->left_child = NULL;
            t->right_child = NULL;
            p->left_child = t;
            enqueue(&q, t);
        }
        printf("Enter %d right child: ", p->data);
        scanf("%d", &value);
        if (value != -1)
        {
            Node *t = (Node *)malloc(sizeof(Node));
            t->data = value;
            t->left_child = NULL;
            t->right_child = NULL;
            p->right_child = t;
            enqueue(&q, t);
        }
    }
}

void preorder(Node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        preorder(p->left_child);
        preorder(p->right_child);
    }
}

void preorder_iter(Node *p)
{
    Node *t = p;
    Stack stk;
    stack_create(&stk, 10);
    while (t != NULL || !stack_is_empty(stk))
    {
        if (t != NULL)
        {
            printf("%d ", t->data);
            stack_push(&stk, t);
            t = t->left_child;
        }
        else
        {
            t = stack_pop(&stk);
            t = t->right_child;
        }
    }
}

void inorder(Node *p)
{
    if (p != NULL)
    {
        inorder(p->left_child);
        printf("%d ", p->data);
        inorder(p->right_child);
    }
}

void inorder_iter(Node *p)
{
    Node *t = p;
    Stack stk;
    stack_create(&stk, 10);
    while (t != NULL || !stack_is_empty(stk))
    {
        if (t != NULL)
        {
            stack_push(&stk, t);
            t = t->left_child;
        }
        else
        {
            t = stack_pop(&stk);
            printf("%d ", t->data);
            t = t->right_child;
        }
    }
}

void postorder(Node *p)
{
    if (p != NULL)
    {
        postorder(p->left_child);
        postorder(p->right_child);
        printf("%d ", p->data);
    }
}

void postorder_iter(Node *p)
{
    Node *t = p;
    Stack stk;
    stack_create(&stk, 10);
    long temp = 0;
    while (t != NULL || !stack_is_empty(stk))
    {
        if (t != NULL)
        {
            stack_push(&stk, t);
            t = t->left_child;
        }
        else
        {
            temp = (long)stack_pop(&stk);
            if (temp > 0)
            {
                stack_push(&stk, (Node *)temp);
                t = ((Node *)temp)->right_child;
            }
            else
            {
                printf("%d ", ((Node *)temp)->data);
                t = NULL;
            }
        }
    }
}

void level_order(Node *root)
{
    Queue q;
    queue_create(&q, 100);
    printf("%d ", root->data);
    enqueue(&q, root);

    while (!queue_is_empty(q))
    {
        root = dequeue(&q);
        if (root->left_child != NULL)
        {
            printf("%d ", root->left_child->data);
            enqueue(&q, root->left_child);
        }
        if (root->right_child != NULL)
        {
            printf("%d ", root->right_child->data);
            enqueue(&q, root->right_child);
        }
    }
}

int count(Node *root)
{
    if (root != NULL)
    {
        return count(root->left_child) + count(root->right_child) + 1;
    }
    return 0;
}

int count_leaf(Node *root)
{
    int x;
    int y;
    if (root != NULL)
    {
        x = count_leaf(root->left_child);
        y = count_leaf(root->right_child);
        if ((root->left_child == NULL) && (root->right_child == NULL))
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}

int count_deg_2(Node *root)
{
    int x;
    int y;
    if (root != NULL)
    {
        x = count_deg_2(root->left_child);
        y = count_deg_2(root->right_child);
        if ((root->left_child != NULL) && (root->right_child != NULL))
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}

int count_deg_2_or_1(Node *root)
{
    int x;
    int y;
    if (root != NULL)
    {
        x = count_deg_2_or_1(root->left_child);
        y = count_deg_2_or_1(root->right_child);
        if ((root->left_child != NULL) || (root->right_child != NULL))
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}

int count_deg_1(Node *root)
{
    int x;
    int y;
    if (root != NULL)
    {
        x = count_deg_1(root->left_child);
        y = count_deg_1(root->right_child);
        if ((root->left_child != NULL) ^ (root->right_child != NULL))
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}

int height(Node *root)
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

Node *inorder_predecessor(Node *p)
{
    while ((p != NULL) && (p->right_child != NULL))
    {
        p = p->right_child;
    }
    return p;
}

Node *inorder_successor(Node *p)
{
    while ((p != NULL) && (p->left_child != NULL))
    {
        p = p->left_child;
    }
    return p;
}

Node *binary_search(Node *root, int key)
{
    /* O(log(n)) */
    Node *t = root;
    while (t != NULL)
    {
        if (t->data == key)
        {
            return t;
        }
        else if (t->data > key)
        {
            t = t->left_child;
        }
        else
        {
            t = t->right_child;
        }
    }
    return t;
}

Node *binary_search_recursive(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (key == root->data)
    {
        return root;
    }

    if (key < root->data)
    {
        return binary_search_recursive(root->left_child, key);
    }

    if (key > root->data)
    {
        return binary_search_recursive(root->right_child, key);
    }

    return NULL;
}

void insert(Node *p, int key)
{
    /* O(log(n)) */
    Node *t = p;
    Node *r = p;

    if (root == NULL)
    {
        Node *t = (Node *)malloc(sizeof(Node));
        t->data = key;
        t->left_child = NULL;
        t->right_child = NULL;
        root = t;
        return;
    }

    while (t != NULL)
    {
        if (t->data == key)
        {
            return;
        }
        else if (t->data > key)
        {
            r = t;
            t = t->left_child;
        }
        else
        {
            r = t;
            t = t->right_child;
        }
    }
    t = (Node *)malloc(sizeof(Node));
    t->data = key;
    t->left_child = NULL;
    t->right_child = NULL;

    if (r->data < t->data)
    {
        r->right_child = t;
    }
    else if (r->data > t->data)
    {
        r->left_child = t;
    }
}

Node *insert_recursive(Node *p, int key)
{
    if (root == NULL)
    {
        Node *t = (Node *)malloc(sizeof(Node));
        t->data = key;
        t->left_child = NULL;
        t->right_child = NULL;
        root = t;
        return t;
    }

    if (p == NULL)
    {
        Node *t = (Node *)malloc(sizeof(Node));
        t->data = key;
        t->left_child = NULL;
        t->right_child = NULL;
        return t;
    }

    if (key < p->data)
    {
        p->left_child = insert_recursive(p->left_child, key);
    }

    if (key > p->data)
    {
        p->right_child = insert_recursive(p->right_child, key);
    }

    return p;
}

Node *delete_node(Node *p, int key)
{
    Node *q;
    if (p == NULL)
    {
        return NULL;
    }

    if ((p->left_child == NULL) && (p->right_child == NULL))
    {
        if (p == root)
        {
            root = NULL;
        }

        free(p);
        return NULL;
    }

    if (key < p->data)
    {
        p->left_child = delete_node(p->left_child, key);
    }
    else if (key > p->data)
    {
        p->right_child = delete_node(p->right_child, key);
    }
    else
    {
        if (height(p->left_child) > height(p->right_child))
        {
            q = inorder_predecessor(p->left_child);
            p->data = q->data;
            p->left_child = delete_node(p->left_child, q->data);
        }
        else
        {
            q = inorder_successor(p->right_child);
            p->data = q->data;
            p->right_child = delete_node(p->right_child, q->data);
        }
    }
    return p;
}

void binary_from_preorder(int *preorder_array, int size)
{
    Stack stk;
    stack_create(&stk, 10);

    int i = 0;

    root = (Node *)malloc(sizeof(Node));
    root->data = preorder_array[i++];
    root->left_child = NULL;
    root->right_child = NULL;

    Node *p = root;
    Node *t = NULL;

    while (i < size)
    {

        if (preorder_array[i] < p->data)
        {
            t = (Node *)malloc(sizeof(Node));
            t->data = preorder_array[i++];
            t->left_child = NULL;
            t->right_child = NULL;

            p->left_child = t;
            stack_push(&stk, p);
            p = t;
        }
        else
        {
            if ((preorder_array[i] > p->data) && (!stack_is_empty(stk)) && (preorder_array[i] < stack_top(stk)->data))
            {
                t = (Node *)malloc(sizeof(Node));
                t->data = preorder_array[i++];
                t->left_child = NULL;
                t->right_child = NULL;

                p->right_child = t;
                p = t;
            }
            else if (stack_is_empty(stk))
            {
                t = (Node *)malloc(sizeof(Node));
                t->data = preorder_array[i++];
                t->left_child = NULL;
                t->right_child = NULL;

                p->right_child = t;
                p = t;
            }
            else
            {
                p = stack_pop(&stk);
            }
        }
    }
}

int main()
{

    insert_recursive(root, 40);
    insert_recursive(root, 20);
    insert_recursive(root, 30);
    insert_recursive(root, 60);
    insert_recursive(root, 50);
    insert_recursive(root, 10);
    insert_recursive(root, 70);
    

    printf("%d\n", height(root));

    printf("Inorder: ");
    inorder_iter(root);
    printf("\n");

    delete_node(root, 40);
    delete_node(root, 20);
    delete_node(root, 30);
    delete_node(root, 60);
    delete_node(root, 50);
    delete_node(root, 10);
    delete_node(root, 70);


    insert_recursive(root, 10);
    insert_recursive(root, 20);
    insert_recursive(root, 30);
    insert_recursive(root, 40);
    insert_recursive(root, 50);
    insert_recursive(root, 60);
    insert_recursive(root, 70);

    printf("%d\n", height(root));

    printf("Inorder: ");
    inorder_iter(root);
    printf("\n");
    return 0;
}
