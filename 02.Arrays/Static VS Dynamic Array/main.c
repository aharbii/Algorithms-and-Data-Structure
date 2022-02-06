#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* Static Array --> Saved in the stack */
    int A[5] = {2, 4, 6, 8, 10};                    // size should be declared during compiling time

    for (int i = 0; i < 5; i++)
    {
        printf("A[%d]: %d\n", i, A[i]);
    }
    


    /* Dynamic Memory Allocation --> Saved in heap with a pointer to it */
    int *p;
    p = (int *) malloc(5 * sizeof(int));       // size can be declared with a variable during runtime
    p[0] = 3;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 11;

    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        printf("P[%d]: %d\n", i, p[i]);
    }
    
    /* Increasing Size Method */
    int *q;
    q = (int *) malloc(10*sizeof(int));

    for (int i = 0; i < 5; i++)
    {
        q[i] = p[i];
    }
    

    /* YOU MUST DELETE THE USED MEMORY MANUALLY FROM THE HEAP */
    free(p);
    p = q;
    q = NULL;

    free(p);

    return 0;
}