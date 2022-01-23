#include <stdio.h>
#include <stdlib.h>

#define ROW_MODE 1
#define COL_MODE 2

void matrix_set(int *array_ptr, int *size, int i, int j, int key, int mode)
{
    if ((i <= j) && (i <= *size) && (j <= *size))
    {
        int index = 0;
        switch (mode)
        {
        case COL_MODE:
            index = ((j * (j - 1)) / 2) + (i - 1);
            break;
        case ROW_MODE:
            index = ((*size * (i - 1)) + (((i - 2) * (i - 1)) / 2)) + (j - i);
            break;
        default:
            break;
        }
        array_ptr[index] = key;
    }
}

int matrix_get(const int *array_ptr, const int *size, int i, int j, int mode)
{
    if ((i <= j) && (i <= *size) && (j <= *size))
    {
        int index = 0;
        switch (mode)
        {
        case COL_MODE:
            index = ((j * (j - 1)) / 2) + (i - 1);
            break;
        case ROW_MODE:
            index = ((*size * (i - 1)) + (((i - 2) * (i - 1)) / 2)) + (j - i);
            break;
        default:
            break;
        }
        return array_ptr[index];
    }
    return 0;
}

void matrix_display(const int *array_ptr, const int *size, int mode)
{
    for (int i = 1; i <= *size; i++)
    {
        for (int j = 1; j <= *size; j++)
        {
            if (i <= j)
            {
                int index = 0;
                switch (mode)
                {
                case COL_MODE:
                    index = ((j * (j - 1)) / 2) + (i - 1);
                    break;
                case ROW_MODE:
                    index = ((*size * (i - 1)) + (((i - 2) * (i - 1)) / 2)) + (j - i);
                    break;
                default:
                    break;
                }
                printf("%d ", array_ptr[index]);
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
    matrix = (int *)calloc((n * (n + 1)) / 2, sizeof(int));
    printf("Enter all elements: ");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int value;
            scanf("%d", &value);
            matrix_set(matrix, &n, i, j, value, ROW_MODE);
        }
    }

    printf("\n\n");
    matrix_display(matrix, &n, ROW_MODE);
    free(matrix);
    return 0;
}