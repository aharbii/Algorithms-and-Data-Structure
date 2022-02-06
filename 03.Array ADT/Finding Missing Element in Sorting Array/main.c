#include <stdio.h>
#include <stdlib.h>

typedef struct Array
{
    int A[100];
    int length;
} Array;

int get_sum(const Array *arr)
{
    /* O(n) */
    int actual_sum = 0;
    for (int i = 0; i < arr->length; i++)
    {
        actual_sum += arr->A[i];
    }
    return actual_sum;
}

int sum_formula(int n)
{
    /* O(1) */
    int sum = (n * (n + 1)) / 2;
    return sum;
}

int get_sum_sequence(const Array *arr)
{
    /* O(1) */
    int max = arr->A[arr->length - 1];
    int min = arr->A[0];
    return sum_formula(max) - sum_formula(min - 1);
}

int get_missing_sorted(const Array *arr)
{
    /* O(n) */
    int actual_sum = get_sum(arr);
    int expected_sum = get_sum_sequence(arr);
    int missing = expected_sum - actual_sum;
    return missing;
}

int get_missing_diff(const Array *arr)
{
    /* O(n) */
    int diff = arr->A[0] - 0;
    for (int i = 0; i < arr->length; i++)
    {
        int current_diff = arr->A[i] - i;
        if (current_diff != diff)
        {
            while (diff < arr->A[i] - i)
            {
                printf("%d\n", i + diff);
                diff += 1;
            }
        }
    }
    return -1;
}

int get_max(const Array *arr)
{
    /* O(n) */
    int max = arr->A[0];
    for (int i = 1; i < arr->length; i++)
    {
        if (max < arr->A[i])
        {
            max = arr->A[i];
        }
    }
    return max;
}

void get_missing_unsorted(const Array *arr)
{
    /* O(n) */
    int max = get_max(arr);
    int *hash_table = (int *)calloc(max, sizeof(int));
    for (int i = 0; i < max; i++)
    {
        hash_table[i] = 0;
    }

    for (int i = 0; i < arr->length; i++)
    {
        hash_table[arr->A[i]] += 1;
    }

    for (int i = 1; i < max; i++)
    {
        if (hash_table[i] == 0)
        {
            printf("%d\n", i);
        }
    }

    free(hash_table);
}

void get_duplicate_sorted(const Array *arr)
{
    /* O(n) */
    int duplicated = 0;
    for (int i = 1; i < arr->length; i++)
    {

        if (arr->A[i] == arr->A[i - 1])
        {
            if (arr->A[i] != duplicated)
            {
                duplicated = arr->A[i];
                printf("%d\n", arr->A[i]);
            }
        }
    }
}

void get_duplicate_hash(const Array *arr)
{
    /* O(n) */
    int max = get_max(arr) + 1;
    int *hash_table = (int *)calloc(max, sizeof(int));
    for (int i = 0; i < max; i++)
    {
        hash_table[i] = 0;
    }

    for (int i = 0; i < arr->length; i++)
    {
        hash_table[arr->A[i]] += 1;
    }

    for (int i = 0; i < max; i++)
    {
        if (hash_table[i] > 1)
        {
            printf("%d --> %d\n", i, hash_table[i]);
        }
    }

    free(hash_table);
}

void pair_with_sum(const Array *arr, int sum)
{
    /* O(n^2) */
    for (int i = 0; i < arr->length; i++)
    {
        for (int j = i + 1; j < arr->length; j++)
        {
            if ((arr->A[i] + arr->A[j]) == sum)
            {
                printf("%d --> %d\n", arr->A[i], arr->A[j]);
            }
        }
    }
}

void pair_with_sum_hashing(const Array *arr, int sum)
{
    /* O(n) */
    int max = get_max(arr) + 1;
    int *hash_table = (int *)calloc(max, sizeof(int));
    for (int i = 0; i < max; i++)
    {
        hash_table[i] = 0;
    }

    for (int i = 0; i < arr->length; i++)
    {
        int need = sum - arr->A[i];
        if (hash_table[need] == 1)
        {
            printf("%d + %d = %d\n", arr->A[i], need, sum);
        }
        hash_table[arr->A[i]] += 1;
    }

    free(hash_table);
}

void pair_with_sum_sorted(const Array *arr, int sum)
{
    /* O(n) */
    int i = 0;
    int j = arr->length - 1;
    while (i < j)
    {
        if ((arr->A[i] + arr->A[j]) == sum)
        {
            printf("%d + %d = %d\n", arr->A[i], arr->A[j], sum);
            i++;
            j--;
        }
        else if ((arr->A[i] + arr->A[j]) > sum)
        {
            j--;
        }
        else if ((arr->A[i] + arr->A[j]) < sum)
        {
            i++;
        }
    }
}

int main()
{
    Array A = {
        .A = {1, 3, 4, 5, 6, 8, 9, 10, 12, 14},
        .length = 10};
    pair_with_sum_sorted(&A, 10);
    return 0;
}