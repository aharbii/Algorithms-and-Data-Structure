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
    stack_create(&stk, 100);
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
    stack_create(&stk, 100);
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
    stack_create(&stk, 100);
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
            temp = (long) stack_pop(&stk);
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

int main()
{
    create();
    printf("Preorder: ");
    preorder_iter(root);
    printf("\n");
    printf("Postorder: ");
    postorder(root);
    printf("\n");
    printf("Inorder: ");
    inorder_iter(root);
    printf("\n");
    printf("Level Order: ");
    level_order(root);
    printf("\n");
    printf("Nodes count: %d\n", count(root));
    printf("Height: %d\n", height(root));
    printf("Leaf count: %d\n", count_leaf_and_non_leaf(root));    
    return 0;
}
