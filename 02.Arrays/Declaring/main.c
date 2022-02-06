#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* Array Declaration and Initialization */

    int A[5];                    // A[0=garbage, 1=grabage, 2=garbage, 3=garbage, 4=garbage]
    int B[5] = {2, 4, 6, 8, 10}; // B[0=2, 1=4, 2=6, 3=8, 4=10]
    int C[5] = {2, 4};           // C[0=2, 1=4, 2=0, 3=0, 4=0]
    int D[5] = {0};              // D[0=0, 1=0, 2=0, 3=0, 4=0]
    int E[] = {2, 4, 6, 8, 10};  // E[0=2, 1=4, 2=6, 3=8, 4=10]    --> implicit size declaration

    /* Accessing Array's Element */

    printf("B[0] = %d\n", B[0]);        // Array_Name[Element_Index]
    printf("\n0[B] = %d\n", 2 [B]);     // Element_Index[Array_Name]
    printf("\n*(B + 2)%d\n", *(B + 2)); // *(pointer to first element of array + offset)

    printf("\nFor loop: \n");
    for (int i = 0; i < 5; i++) // Accessing all arrays elements
    {
        printf("B[%d] = %d\n", i, B[i]);
    }

    return 0;
}