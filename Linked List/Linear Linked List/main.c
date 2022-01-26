#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *first = NULL;
Node *second = NULL;
Node *third = NULL;

void create_first(int *array_ptr, int size)
{
    if (size == 0)
    {
        return;
    }

    first = (Node *)malloc(sizeof(Node));
    first->data = array_ptr[0];
    first->next = NULL;
    Node *t = NULL;
    Node *last = first;

    for (int i = 1; i < size; i++)
    {
        t = (Node *)malloc(sizeof(Node));
        t->data = array_ptr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create_second(int *array_ptr, int size)
{
    if (size == 0)
    {
        return;
    }

    second = (Node *)malloc(sizeof(Node));
    second->data = array_ptr[0];
    second->next = NULL;
    Node *t = NULL;
    Node *last = second;

    for (int i = 1; i < size; i++)
    {
        t = (Node *)malloc(sizeof(Node));
        t->data = array_ptr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(Node *p)
{
    /* time --> space */
    /* O(n) --> O(1) */
    if (p == NULL)
    {
        return;
    }

    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void display_recursive(Node *p)
{
    /* O(n) */
    if (p != NULL)
    {
        printf("%d ", p->data);
        display_recursive(p->next);
    }
}

void display_recursive_reversed(Node *p)
{
    /* O(n) */
    if (p != NULL)
    {
        display_recursive_reversed(p->next);
        printf("%d ", p->data);
    }
}

int count_nodes(Node *p)
{
    /* O(n) */
    int count = 0;
    while (p != NULL)
    {
        count += 1;
        p = p->next;
    }
    return count;
}

int count_nodes_recursive(Node *p)
{
    /* O(n) */
    if (p == NULL)
    {
        return 0;
    }
    return 1 + count_nodes_recursive(p->next);
}

int sum_nodes(Node *p)
{
    /* O(n) */
    int sum = 0;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int sum_nodes_recursive(Node *p)
{
    /* O(n) */
    if (p == NULL)
    {
        return 0;
    }
    return p->data + sum_nodes_recursive(p->next);
}

int get_max(Node *p)
{
    /* O(n) */
    int max = p->data;
    while (p != NULL)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

int get_max_recursive(Node *p)
{
    /* O(n) */
    int x = 0;
    if (p == NULL)
    {
        return INT32_MIN;
    }
    x = get_max_recursive(p->next);
    return x > p->data ? x : p->data;
}

int get_min(Node *p)
{
    /* O(n) */
    int min = p->data;
    while (p != NULL)
    {
        if (p->data < min)
        {
            min = p->data;
        }
        p = p->next;
    }
    return min;
}

int get_min_recursive(Node *p)
{
    /* O(n) */
    int x = 0;
    if (p == NULL)
    {
        return INT32_MAX;
    }
    x = get_min_recursive(p->next);
    return x < p->data ? x : p->data;
}

Node *linear_search(Node *p, int key)
{
    /* O(n) */
    while (p != NULL)
    {
        if (p->data == key)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

Node *linear_search_recursive(Node *p, int key)
{
    /* O(n) */
    if (p == NULL)
    {
        return NULL;
    }
    if (p->data == key)
    {
        return p;
    }
    return linear_search_recursive(p->next, key);
}

Node *improved_linear_search(Node *p, int key)
{
    /* O(n) */
    Node *q = NULL;
    while (p != NULL)
    {
        if (p->data == key)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return first;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

/* Binary Search CANNOT be perfomed on Linked Lists */

void insert_node(Node *p, int key, int index)
{
    /* O(n) */
    if ((index < 0) || (index > count_nodes(p)))
    {
        return;
    }

    Node *t = (Node *)malloc(sizeof(Node));
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

void append_nodes(Node *p, int key)
{
    /* O(n) */
    Node *t = (Node *)malloc(sizeof(Node));
    t->data = key;
    t->next = NULL;
    if (first == NULL)
    {
        first = t;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void insert_sorted(Node *p, int key)
{
    /* O(n) */
    Node *t = (Node *)malloc(sizeof(Node));
    t->data = key;
    t->next = NULL;
    if (first == NULL)
    {
        first = t;
    }
    else
    {
        Node *q = NULL;
        while ((p != NULL) && (p->data < key))
        {
            q = p;
            p = p->next;
        }
        if (q == NULL)
        {
            t->next = p;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int delete_node(Node *p, int index)
{
    /* O(n) */
    if ((index < 1) || (index > count_nodes(p)))
    {
        return -1;
    }

    Node *q = NULL;
    int x = 0;
    if (index == 1)
    {
        q = first;
        first = first->next;
        x = q->data;
        free(q);
    }
    else
    {
        for (int i = 1; i < index; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
    }
    return x;
}

int is_sorted(Node *p)
{
    /* O(n) */
    int x = INT32_MIN;
    int sorted = 1;
    while ((p != NULL) && sorted)
    {
        if (p->data >= x)
        {
            x = p->data;
            p = p->next;
        }
        else
        {
            sorted = 0;
        }
    }
    return sorted;
}

void remove_duplicates(Node *p)
{
    if (p == NULL)
    {
        return;
    }

    Node *q = p->next;
    while (q != NULL)
    {
        if (p->data == q->data)
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
        else
        {
            p = p->next;
            q = q->next;
        }
    }
}

void reverse_elements(Node *p)
{
    /* O(n) */
    int *A = (int *)calloc(count_nodes(p), sizeof(int));
    int i = 0;
    while (p != NULL)
    {
        A[i] = p->data;
        p = p->next;
        i++;
    }
    p = first;
    i--;
    while (p != NULL)
    {
        p->data = A[i];
        p = p->next;
        i--;
    }
    free(A);
}

void reverse_nodes(Node *p)
{
    /* O(n) */
    /* Sliding Pointers */
    Node *q = NULL;
    Node *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void reverse_recursive(Node *q, Node *p)
{
    if (p == NULL)
    {
        first = q;
    }
    else
    {
        reverse_recursive(p, p->next);
        p->next = q;
    }
}

void concatenate(Node *p, Node *q)
{
    third = p;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
}

void merge(Node *p, Node *q)
{
    if (third != NULL)
    {
        return;
    }
    
    Node *last = NULL;
    if (p->data < q->data)
    {
        third = p;
        last = p;
        p = p->next;
        last->next = NULL;
    }
    else
    {
        third = q;
        last = q;
        q = q->next;
        last->next = NULL;
    }

    while ((p != NULL) && (q != NULL))
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }

    if (p != NULL)
    {
        last->next = p;
    }
    if (q != NULL)
    {
        last->next = q;
    }
}

int is_loop(Node *f)
{
    Node *p = f;
    Node *q = f;
    int found_loop = 0;
    while ((p != NULL) && (q != NULL) && !found_loop)
    {
        p = p->next;
        q = q->next;
        (q == NULL) ? (q = q) : (q = q->next);
        if (p == q)
        {
            found_loop = 1;
        }
    }
    if (found_loop)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int A[] = {10, 18, 26, 30, 56};
    create_first(A, 5);

    display(first);

    return 0;
}