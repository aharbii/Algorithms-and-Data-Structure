#include <iostream>

int main()
{
    /* Static Array --> Saved in the stack */
    int n;
    std::cin >> n;
    int A[n];        // in C++ you can declaring array with variable size during runtime

    /* Dynamic Memory Allocation --> Saved in heap with a pointer to it */
    int *p;
    p = new int[5];
    p[0] = 5;
    p[1] = 8;
    p[2] = 9;
    p[3] = 6;
    p[4] = 4;


    /* Increasing Size Method */
    int *q;
    q = new int[10];

    for (int i = 0; i < 5; i++)
    {
        q[i] = p[i];
    }
    

    /* YOU MUST DELETE THE USED MEMORY MANUALLY */
    delete []p;
    p = q;
    q = NULL;

    for (int i = 0; i < 10; i++)
    {
        printf("P[%d]: %d\n", i, p[i]);
    }

    delete []p;    

    return 0;
}