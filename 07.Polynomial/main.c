#include <stdio.h>
#include <stdlib.h>

typedef struct Term
{
    int coeff;
    int exp;
} Term;

typedef struct Polynomial
{
    int n;
    Term *t;
} Polynomial;

int power(int base, int exp)
{
    int result = 1;
    for (int i = 0; i < exp; i++)
    {
        result *= base;
    }
    return result;
    
}

int evaluate(Polynomial p)
{
    int x;
    printf("Enter x value: ");
    scanf("%d", &x);
    int px = 0;
    for (int i = 0; i < p.n; i++)
    {
        px += (p.t[i].coeff * power(x, p.t[i].exp));
    }
    return px;
}

Polynomial *addition(Polynomial A, Polynomial B)
{
    Polynomial *R;
    R = (Polynomial *)malloc(sizeof(Polynomial));
    R->n = A.n + B.n;
    R->t = (Term *)calloc(R->n, sizeof(Term));
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < A.n && j < B.n)
    {
        if (A.t[i].exp > B.t[j].exp)
        {
            R->t[k++] = A.t[i++];
        }
        else if (A.t[i].exp < B.t[j].exp)
        {
            R->t[k++] = B.t[j++];
        }
        else
        {
            R->t[k] = A.t[i++];
            R->t[k++].coeff += B.t[j++].coeff;
        }
    }
    while (i < A.n)
    {
        R->t[k++] = A.t[i++];
    }
    while (j < B.n)
    {
        R->t[k++] = B.t[j++];
    }
    R->n = k;
    return R;
}

void display(Polynomial P)
{
    for (int i = 0; i < P.n; i++)
    {
        printf("%dx%d", P.t[i].coeff, P.t[i].exp);
        if ((P.n - i) == 1)
        {
            printf("\n");
        }
        else
        {
            printf("+");
        }
        
    }
    
}

void create(Polynomial *k)
{
    printf("Enter number of terms: ");
    scanf("%d", &k->n);
    k->t = (Term *)calloc(k->n, sizeof(Term));
    printf("Enter polynomial terms: \n");
    for (int i = 0; i < k->n; i++)
    {
        printf("term[%d]: ", i + 1);
        scanf("%d%d", &k->t[i].coeff, &k->t[i].exp);
    }
}

int main()
{
    Polynomial p;
    create(&p);
    display(p);
    Polynomial k;
    create(&k);
    display(k);
    
    Polynomial *f = addition(p, k);
    display(*f);

    int px = evaluate(p);
    printf("p(x) = %d\n", px);
    int kx = evaluate(k);
    printf("k(x) = %d\n", kx);
    int fx = evaluate(*f);
    printf("f(x) = %d\n", fx);

    free(p.t);
    free(k.t);
    free(f->t);
    return 0;
}
