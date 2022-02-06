#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int j;
    int val;
    struct Node *next;
} Node;

typedef struct SparseMatrix
{
    int m;
    int n;
    Node *A;
} SparseMatrix;

void create_matrix(SparseMatrix *m)
{
    printf("Enter dimensions: ");
    scanf("%d%d", &m->m, &m->n);
    m->A = (Node *)calloc(m->m, sizeof(Node));
    int non_zero;
    printf("Enter number of non-zero elements: ");
    scanf("%d", &non_zero);
    printf("Enter elements: ");
    for (int i = 0; i < non_zero; i++)
    {
        int row, col, val;
        scanf("%d%d%d", &row, &col, &val);
        Node *t = (Node *)malloc(sizeof(Node));
        t->j = col;
        t->val = val;
        t->next = NULL;

        if (m->A[row].val == 0)
        {
            m->A[row].j = col;
            m->A[row].val = val;
            m->A[row].next = NULL;
        }
        else
        {
            m->A[row].next = t;
        }
    }
}

void display_matrix(const SparseMatrix m)
{
    for (int i = 0; i < m.m; i++)
    {
        Node *index = m.A + i;
        for (int j = 0; j < m.n; j++)
        {
            if ((index != NULL) && index->j == j)
            {
                printf("%d ", index->val);
                index = index->next;
            }
            else
            {
                printf("0 ");
            }
            
        }
        printf("\n");
    }
}

int main()
{
    SparseMatrix m;
    create_matrix(&m);
    display_matrix(m);
    
    return 0;
}