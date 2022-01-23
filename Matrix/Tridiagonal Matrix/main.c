#include <stdio.h>
#include <stdlib.h>

void matrix_set(int *array_ptr, int n, int i, int j, int key)
{
    if ((i - j) == 1)
    {
        int index = i - 2;
        array_ptr[index] = key;
    }
    else if ((i - j) == 0)
    {
        int index = ((n) - 1) + (i - 1);
        array_ptr[index] = key;
    }
    else if ((i - j) == -1)
    {
        int index = ((2 * n) - 1) + (i - 1);
        array_ptr[index] = key;
    }
}

int matrix_get(const int *array_ptr, const int n, int i, int j)
{
    if ((i - j) == 1)
    {
        int index = i - 2;
        return array_ptr[index];
    }
    else if ((i - j) == 0)
    {
        int index = ((n) - 1) + (i - 1);
        return array_ptr[index];
    }
    else if ((i - j) == -1)
    {
        int index = ((2 * n) - 1) + (i - 1);
        return array_ptr[index];
    }
    return 0;
}

void matrix_display(const int *array_ptr, int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ((i - j) == 1)
            {
                int index = i - 2;
                int value = array_ptr[index];
                printf("%d ", value);
            }
            else if ((i - j) == 0)
            {
                int index = ((n) - 1) + (i - 1);
                int value = array_ptr[index];
                printf("%d ", value);
            }
            else if ((i - j) == -1)
            {
                int index = ((2 * n) - 1) + (i - 1);
                int value = array_ptr[index];
                printf("%d ", value);
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
    int *matrix;
    int n;
    printf("Enter dimension: ");
    scanf("%d", &n);
    matrix = (int *)calloc((3 * n) - 2, sizeof(int));
    
    printf("Enter all elements: ");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int value;
            scanf("%d", &value);
            matrix_set(matrix, n, i, j, value);
        }
    }
    
    printf("\n\n");
    matrix_display(matrix, n);
    free(matrix);
    return 0;
}