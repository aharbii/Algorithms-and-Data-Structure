#include <stdlib.h>
#include <stdio.h>

int main()
{
    /* All in stack */

    int A[3][4] = {{1, 2, 3, 4}, {2, 4, 6, 8}, {3, 5, 7, 9}}; // All in Stack

    /* O(n^2) --> Accessing Array */
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d: %d - ", A[i][j], &A[i][j]);
            /* A[m][n] */
            /* A[i][j] = L0 + [i * n + j] * w */ 
            /* A[1][2] = A  + [1 * 4 + 2] * 4 */
            
        }
        printf("\n");
    }

    printf("\n======================\n");

    /* First pointer and second pointers(Array of pointers) in stack --> Elements in heap */

    int *B[3];                             // B --> in stack
                                           // B[0], B[1], B[2] is in stack
    B[0] = (int *)malloc(4 * sizeof(int)); // B[0][0], B[0][1], B[0][2], B[0][3] --> in heap
    B[1] = (int *)malloc(4 * sizeof(int)); // B[1][0], B[1][1], B[1][2], B[1][3] --> in heap
    B[2] = (int *)malloc(4 * sizeof(int)); // B[2][0], B[2][1], B[2][2], B[2][3] --> in heap

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            B[i][j] = i + j;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    for (int i = 2; i >= 0; i--)
    {
        free(B[i]);
    }

    printf("\n======================\n");

    /* First pointer in Stack --> second pointers(Array of pointers), and elements in heap */

    int **C;                               // C --> in stack
    C = (int **)malloc(3 * sizeof(int *)); // C[0], C[1], C[2] --> in heap
    C[0] = (int *)malloc(4 * sizeof(int)); // C[0][0], C[0][1], C[0][2], C[0][3] --> in heap
    C[1] = (int *)malloc(4 * sizeof(int)); // C[1][0], C[1][1], C[1][2], C[1][3] --> in heap
    C[2] = (int *)malloc(4 * sizeof(int)); // C[2][0], C[2][1], C[2][2], C[2][3] --> in heap

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            C[i][j] = i + j;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    printf("\n======================\n");
    for (int i = 2; i >= 0; i--)
    {
        free(C[i]);
    }

    free(C);

    return 0;
}