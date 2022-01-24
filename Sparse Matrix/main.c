#include <stdio.h>
#include <stdlib.h>

typedef struct Element
{
    int i;
    int j;
    int value;
} Element;

typedef struct SparseMatrix
{
    int m;
    int n;
    int num;
    Element *e;
} SparseMatrix;

void create(SparseMatrix *s)
{
    printf("Enter dimensions: ");
    scanf("%d%d", &s->m, &s->n);
    printf("Enter number of non-zero Elements: ");
    scanf("%d", &s->num);

    s->e = (Element *)calloc(s->num, sizeof(Element));
    printf("Enter all elements: ");
    for (int i = 0; i < s->num; i++)
    {
        scanf("%d%d%d", &s->e[i].i, &s->e[i].j, &s->e[i].value);
    }
}

void display(SparseMatrix s)
{
    printf("\n\n");
    int k = 0;
    for (int i = 1; i <= s.m; i++)
    {
        for (int j = 1; j <= s.n; j++)
        {
            if ((i == s.e[k].i) && (j == s.e[k].j))
            {
                printf("%2d ", s.e[k].value);
                k++;
            }
            else
            {
                printf(" 0 ");
            }
        }
        printf("\n");
    }
}

SparseMatrix *add(SparseMatrix A, SparseMatrix B)
{
    if ((A.m != B.m) || (A.n != B.n))
    {
        return NULL;
    }

    SparseMatrix *sum = (SparseMatrix *)malloc(sizeof(SparseMatrix));
    sum->m = A.m;
    sum->n = A.n;
    sum->num = 0;
    sum->e = (Element *)calloc(A.num + B.num, sizeof(Element));
    int k = 0;
    int i = 0;
    int j = 0;
    while (i < A.num && j < B.num)
    {
        if (A.e[i].i < B.e[j].i)
        {
            sum->e[k++] = A.e[i++];
        }
        else if (A.e[i].i > B.e[j].i)
        {
            sum->e[k++] = B.e[j++];
        }
        else
        {
            if (A.e[i].j < B.e[j].j)
            {
                sum->e[k++] = A.e[i++];
            }
            else if (A.e[i].j > B.e[j].j)
            {
                sum->e[k++] = B.e[j++];
            }
            else
            {
                sum->e[k].i = A.e[i].i;
                sum->e[k].j = A.e[i].j;
                sum->e[k].value = A.e[i].value + B.e[j].value;
                k++;
                i++;
                j++;
            }
        }
        sum->num += 1;
    }
    while (i < A.num)
    {
        sum->e[k++] = A.e[i++];
    }
    while (j < B.num)
    {
        sum->e[k++] = B.e[j++];
    }
    
    return sum;
}

int main()
{
    SparseMatrix A;
    create(&A);
    display(A);
    SparseMatrix B;
    create(&B);
    display(B);

    SparseMatrix *sum = add(A, B);
    display(*sum);
    free(A.e);
    free(B.e);
    free(sum->e);
    free(sum);
    return 0;
}
