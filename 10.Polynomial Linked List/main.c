#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int coeff;
    int exp;
    struct Node *next;

} Node;

Node *polynomial = NULL;
Node *polynomial2 = NULL;
Node *add = NULL;

int power(int base, int exp)
{
    int result = 1;
    for (int i = 0; i < exp; i++)
    {
        result *= base;
    }
    return result;
}

int evaluate(Node *p)
{
    int x;
    printf("Enter x value: ");
    scanf("%d", &x);
    int px = 0;
    while (p != NULL)
    {
        px += (p->coeff * power(x, p->exp));
        p = p->next;
    }
    return px;
}

void addition(Node *A, Node *B)
{
    Node *r = add;
    Node *p = polynomial;
    Node *q = polynomial2;
    if (p->exp < q->exp)
    {
        add = q;
        r = q;
        q = q->next;
        r->next = NULL;
    }
    else
    {
        add = p;
        r = p;
        p = p->next;
        r->next = NULL;
    }

    while ((p != NULL) && (q != NULL))
    {
        if (p->exp > q->exp)
        {
            r->next = p;
            r = p;
            p = p->next;
            r->next = NULL;
        }
        else if (p->exp < q->exp)
        {
            r->next = q;
            r = q;
            q = q->next;
            r->next = NULL;
        }
        else
        {
            r->next = p;
            r = p;
            p = p->next;
            r->coeff = r->coeff + q->coeff;
            q = q->next;
            r->next = NULL;
        }
    }
    
    if (p != NULL)
    {
        r->next = p;
    }
    if (q != NULL)
    {
        r->next = q;
    }
}

void display(Node *p)
{
    while (p != NULL)
    {
        printf("%dx%d", p->coeff, p->exp);
        if (p->next == NULL)
        {
            printf("\n");
        }
        else
        {
            printf("+");
        }
        p = p->next;
    }
}

void create_first()
{
    int n;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    printf("Enter polynomial terms: \n");
    for (int i = 0; i < n; i++)
    {
        Node *t = (Node *)malloc(sizeof(Node));
        printf("term[%d]: ", i + 1);
        int coeff, exp;
        scanf("%d%d", &coeff, &exp);
        t->coeff = coeff;
        t->exp = exp;
        t->next = NULL;
        if (polynomial == NULL)
        {
            polynomial = t;
        }
        else
        {
            Node *p = polynomial;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = t;
        }
    }
}

void create_second()
{
    int n;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    printf("Enter polynomial terms: \n");
    for (int i = 0; i < n; i++)
    {
        Node *t = (Node *)malloc(sizeof(Node));
        printf("term[%d]: ", i + 1);
        int coeff, exp;
        scanf("%d%d", &coeff, &exp);
        t->coeff = coeff;
        t->exp = exp;
        t->next = NULL;
        if (polynomial2 == NULL)
        {
            polynomial2 = t;
        }
        else
        {
            Node *p = polynomial2;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = t;
        }
    }
}

int main()
{
    create_first();
    display(polynomial);
    int px = evaluate(polynomial);
    printf("p(x) = %d\n", px);

    create_second();
    display(polynomial2);
    int kx = evaluate(polynomial2);
    printf("k(x) = %d\n", kx);

    addition(polynomial, polynomial2);
    display(add);

    int fx = evaluate(add);
    printf("f(x) = %d\n", fx);

    return 0;
}
