#include <stdio.h>
#include <stdlib.h>

#define ROW_MODE 1
#define COL_MODE 2

void matrix_set(int *array_ptr, int *size, int i, int j, int key, int mode)
{
    if ((i >= j) && (i <= *size) && (j <= *size))
    {
        int index = 0;
        switch (mode)
        {
        case ROW_MODE:
            index = ((i * (i - 1)) / 2) + (j - 1);
            break;
        case COL_MODE:
            index = *size * (j - 1) + (j - 2) * (j - 1) / 2 + i - j;
            break;
        default:
            break;
        }
        array_ptr[index] = key;
    }
}

int matrix_get(const int *array_ptr, const int *size, int i, int j, int mode)
{
    if ((i < j) && (i <= *size) && (j <= *size))
    {
        int temp = i;
        i = j;
        j = temp;
    }
    int index = 0;
    switch (mode)
    {
    case ROW_MODE:
        index = ((i * (i - 1)) / 2) + (j - 1);
        break;
    case COL_MODE:
        index = *size * (j - 1) + (j - 2) * (j - 1) / 2 + i - j;
        break;
    default:
        break;
    }
    return array_ptr[index];
}

void matrix_display(const int *array_ptr, const int *size, int mode)
{
    for (int i = 1; i <= *size; i++)
    {
        for (int j = 1; j <= *size; j++)
        {
            int x = i;
            int y = j;
            if (x < y)
            {
                int temp = x;
                x = y;
                y = temp;
            }

            int index = 0;
            switch (mode)
            {
            case ROW_MODE:
                index = ((x * (x - 1)) / 2) + (y - 1);
                break;
            case COL_MODE:
                index = *size * (y - 1) + (y - 2) * (y - 1) / 2 + x - y;
                break;
            default:
                break;
            }
            printf("%d ", array_ptr[index]);
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
            matrix_set(matrix, &n, i, j, value, COL_MODE);
        }
    }

    printf("\n\n");
    matrix_display(matrix, &n, COL_MODE);
    free(matrix);
    return 0;
}