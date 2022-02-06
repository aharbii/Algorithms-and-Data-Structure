#include <stdio.h>
#include <stdlib.h>

void matrix_set(int *array_ptr, int n, int i, int j, int key)
{
    if (i == 1)
    {
        int index = j - 1;
        array_ptr[index] = key;
    }
    else if (j == 1)
    {
        int index = n + (i - 2);
        array_ptr[index] = key;
    }
}

int matrix_get(const int *array_ptr, const int n, int i, int j)
{
    if (i <= j)
    {
        int index = j - i;
        return array_ptr[index];
    }
    else if (j == 1)
    {
        int index = n + (i - j - 1);
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
            if (i <= j)
            {
                int index = j - i;
                int value = array_ptr[index];
                printf("%d ", value);
            }
            else if (i > j)
            {
                int index = n + (i - j - 1);
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
    matrix = (int *)calloc(n + (n - 1), sizeof(int));

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