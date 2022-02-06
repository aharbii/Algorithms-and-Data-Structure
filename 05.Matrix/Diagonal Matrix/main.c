#include <stdio.h>
#include <stdlib.h>

void matrix_set(int *array_ptr, int *size, int i, int j, int key)
{
    if ((i == j) && (i <= *size) && (j <= *size))
    {
        array_ptr[i - 1] = key;
    }
}

int matrix_get(const int *array_ptr, const int *size, int i, int j)
{
    if ((i == j) && (i <= *size) && (j <= *size))
    {
        return array_ptr[i - 1];
    }
    return 0;
}

void matrix_display(const int *array_ptr, const int *size)
{
    for (int i = 0; i < *size; i++)
    {
        for (int j = 0; j < *size; j++)
        {
            if (i == j)
            {
                printf("%d ", array_ptr[i]);
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
    int matrix[10];
    int size = 4;
    matrix_set(matrix, &size, 1, 1, 5);
    matrix_set(matrix, &size, 2, 2, 8);
    matrix_set(matrix, &size, 3, 3, 9);
    matrix_set(matrix, &size, 4, 4, 12);
    printf("%d \n", matrix_get(matrix, &size, 2, 2));
    matrix_display(matrix, &size);
    return 0;
}