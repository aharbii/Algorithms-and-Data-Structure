#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *left_child;
    int data;
    int height;
    struct Node *right_child;
} Node;

Node *root = NULL;

int node_height(Node *p)
{
    int height_left = ((p && p->left_child) ? p->left_child->height : 0);
    int height_right = ((p && p->right_child) ? p->right_child->height : 0);

    return ((height_left > height_right) ? (height_left + 1) : (height_right + 1));
}

int balance_factor(Node *p)
{
    int height_left = ((p && p->left_child) ? p->left_child->height : 0);
    int height_right = ((p && p->right_child) ? p->right_child->height : 0);

    return (height_left - height_right);
}

Node *LL_rotation(Node *p)
{
    Node *pl = p->left_child;
    Node *plr = pl->right_child;

    pl->right_child = p;
    p->left_child = plr;

    p->height = node_height(p);
    pl->height = node_height(pl);

    if (root == p)
    {
        root = pl;
    }

    return pl;
}

Node *LR_rotation(Node *p)
{
    Node *pl = p->left_child;
    Node *plr = pl->right_child;

    pl->right_child = plr->left_child;
    p->left_child = plr->right_child;

    plr->left_child = pl;
    plr->right_child = p;
    
    p->height = node_height(p);
    pl->height = node_height(pl);
    plr->height = node_height(plr);

    if (root == p)
    {
        root = plr;
    }

    return plr;
}

Node *RR_rotation(Node *p)
{
    Node *pr = p->right_child;
    Node *prl = pr->left_child;

    pr->left_child = p;
    p->right_child = prl;

    p->height = node_height(p);
    pr->height = node_height(pr);

    if (root == p)
    {
        root = pr;
    }

    return pr;
}

Node *RL_rotation(Node *p)
{
    Node *pr = p->right_child;
    Node *prl = pr->left_child;

    pr->left_child = prl->right_child;
    p->right_child = prl->left_child;

    prl->left_child = p;
    prl->right_child = pr;

    p->height = node_height(p);
    pr->height = node_height(pr);
    prl->height = node_height(prl);

    if (root == p)
    {
        root = prl;
    }

    return prl;
}

Node *insert_recursive(Node *p, int key)
{
    Node *t = NULL;

    if (p == NULL)
    {
        t = (Node *)malloc(sizeof(Node));
        t->data = key;
        t->height = 1;
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

    p->height = node_height(p);

    if ((balance_factor(p) == 2) && (balance_factor(p->left_child) == 1))
    {
        return LL_rotation(p);
    }
    else if ((balance_factor(p) == 2) && (balance_factor(p->left_child) == -1))
    {
        return LR_rotation(p);
    }
    else if ((balance_factor(p) == -2) && (balance_factor(p->right_child) == -1))
    {
        return RR_rotation(p);
    }
    else if ((balance_factor(p) == -2) && (balance_factor(p->right_child) == 1))
    {
        return RL_rotation(p);
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

int main()
{
    root = insert_recursive(root, 10);
    insert_recursive(root, 20);
    insert_recursive(root, 30);
    insert_recursive(root, 25);
    insert_recursive(root, 28);
    insert_recursive(root, 27);
    insert_recursive(root, 5);

    return 0;
}
