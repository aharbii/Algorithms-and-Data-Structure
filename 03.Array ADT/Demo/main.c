#include <stdio.h>
#include <stdlib.h>

typedef struct Array
{
    int A[100];
    int size;
    int length;
} Array;

void display_array(const Array *arr)
{
    /* O(n) */
    printf("Elements are: ");
    for (int i = 0; i < arr->length; i++)
    {
        printf("%2d ", arr->A[i]);
    }
    printf("\n");
}

void append(Array *arr, int x)
{
    /* O(1) */
    if (arr->length < arr->size)
    {
        arr->A[arr->length] = x;
        arr->length++;
    }
}

void insert(Array *arr, int index, int value)
{
    /* O(n) */
    if ((index >= 0) && (index <= arr->length))
    {
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = value;
        arr->length++;
    }
}

int delete_element(Array *arr, int index)
{
    /* O(n) */
    int x = 0;
    if ((index >= 0) && (index <= arr->length))
    {
        x = arr->A[index];
        arr->A[index] = 0;
        for (int i = index; i < (arr->length - 1); i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

int linear_search(Array *arr, int key)
{
    /* O(n) */
    for (int i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            return i;
        }
    }
    return -1;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int improved_linear_search(Array *arr, int key)
{
    /* O(n) */
    for (int i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}

int binary_search(Array *arr, int key)
{
    /* O(log(n)) */
    int l = 0;
    int h = arr->length - 1;
    while ((l <= h))
    {
        int mid = (h + l) / 2;
        if (arr->A[mid] == key)
        {
            return mid;
        }
        else if (arr->A[mid] > key)
        {
            h = mid - 1;
        }
        else if (arr->A[mid] < key)
        {
            l = mid + 1;
        }
    }
    return -1;
}

int binary_search_recursive(Array *arr, int l, int h, int key)
{
    /* O(log(n)) */
    if (l <= h)
    {
        int mid = (l + h) / 2;
        if (arr->A[mid] == key)
        {
            return mid;
        }
        else if (arr->A[mid] > key)
        {
            return binary_search_recursive(arr, l, mid - 1, key);
        }
        else if (arr->A[mid] < key)
        {
            return binary_search_recursive(arr, mid + 1, h, key);
        }
    }
    return -1;
}

int get(const Array *arr, int index)
{
    /* O(1) */
    if ((index >= 0) && (index <= arr->length))
    {
        return arr->A[index];
    }
    return -1;
}

void set(Array *arr, int index, int key)
{
    /* O(1) */
    if ((index >= 0) && (index <= arr->length))
    {
        arr->A[index] = key;
    }
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

int get_min(const Array *arr)
{
    /* O(n) */
    int min = arr->A[0];
    for (int i = 0; i < arr->length; i++)
    {
        if (min > arr->A[i])
        {
            min = arr->A[i];
        }
    }
    return min;
}

int get_sum(const Array *arr)
{
    /* O(n) */
    int sum = 0;
    for (int i = 0; i < arr->length; i++)
    {
        sum += arr->A[i];
    }
    return sum;
}

int get_sum_recursive(const Array *arr, int n)
{
    /* O(n) */
    if (n < 0)
    {
        return 0;
    }

    return arr->A[n] + get_sum_recursive(arr, n - 1);
}

double get_average(const Array *arr)
{
    /* O(n) */
    int total = 0;
    for (int i = 0; i < arr->length; i++)
    {
        total += arr->A[i];
    }

    double average = (double)total / arr->length;
    return average;
}

void reverse(Array *arr)
{
    /* O(n) */
    Array B = {
        .A = {0},
        .length = arr->length,
        .size = arr->size};
    for (int i = (arr->length - 1), j = 0; i >= 0; i--, j++)
    {
        B.A[j] = arr->A[i];
    }

    for (int i = 0; i < arr->length; i++)
    {
        arr->A[i] = B.A[i];
    }
}

void reverse_swap(Array *arr)
{
    /* O(n) */
    for (int i = 0, j = (arr->length - 1); i < j; i++, j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
}

void insert_sorted(Array *arr, int value)
{
    /* O(n) */
    int i = arr->length - 1;
    while ((arr->A[i] > value) && (i >= 0))
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = value;
    arr->length++;
}

int is_sorted(Array *arr)
{
    /* O(n) */
    for (int i = 0; i < (arr->length - 1); i++)
    {
        if (arr->A[i] > arr->A[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

void rearrange(Array *arr)
{
    int i = 0;
    int j = arr->length - 1;
    while (i < j)
    {
        while (arr->A[i] < 0)
        {
            i++;
        }
        while (arr->A[j] >= 0)
        {
            j--;
        }
        if (i < j)
        {
            swap(&arr->A[i], &arr->A[j]);
        }
    }
}

void merge_array(const Array *A, const Array *B, Array *C)
{
    /* O(m + n) */
    int i = 0;
    int j = 0;
    int k = 0;
    while ((i < A->length) && (j < B->length))
    {
        if (A->A[i] < B->A[j])
        {
            C->A[k++] = A->A[i++];
        }
        else
        {
            C->A[k++] = B->A[j++];
        }
    }

    while (i < A->length)
    {
        C->A[k++] = A->A[i++];
    }
    while (j < B->length)
    {
        C->A[k++] = B->A[j++];
    }
    C->length = k;
    C->size = k * sizeof(int);
}

void union_array(const Array *A, const Array *B, Array *C)
{
    /* O(n^2) */
    int i = 0;
    int j = 0;
    int k = 0;
    C->length = 0;
    for (int i = 0; i < A->length; i++)
    {
        C->A[k++] = A->A[i];
        C->length++;
    }

    for (int i = 0; i < B->length; i++)
    {
        int is_found = 0;
        for (int j = 0; (j < C->length) && (!is_found); j++)
        {
            if (B->A[i] == C->A[j])
            {
                is_found = 1;
            }
        }

        if (!is_found)
        {
            C->A[k++] = B->A[i];
            C->length++;
        }
    }
}

void union_array_sorted(const Array *A, const Array *B, Array *C)
{
    /* O(n^2) */
    int i = 0;
    int j = 0;
    int k = 0;
    C->length = 0;
    while ((i < A->length) && (j < B->length))
    {
        if (A->A[i] < B->A[j])
        {
            C->A[k++] = A->A[i++];
            C->length++;
        }
        else if (A->A[i] == B->A[j])
        {
            C->A[k++] = B->A[i++];
            j++;
            C->length++;
        }
        else if (A->A[i] > B->A[j])
        {
            C->A[k++] = B->A[j++];
            C->length++;
        }
    }

    while (i < A->length)
    {
        C->A[k++] = A->A[i++];
        C->length++;
    }
    while (j < B->length)
    {
        C->A[k++] = B->A[j++];
        C->length++;
    }
}

void intersection_array(const Array *A, const Array *B, Array *C)
{
    /* O(n^2) */
    C->length = 0;
    int k = 0;
    for (int i = 0; i < A->length; i++)
    {
        for (int j = 0; j < B->length; j++)
        {
            if (A->A[i] == B->A[j])
            {
                C->A[k++] = A->A[i];
                C->length++;
            }
        }
    }
}

void intersection_array_sorted(const Array *A, const Array *B, Array *C)
{
    /* O(n) */
    int i = 0;
    int j = 0;
    int k = 0;
    C->length = 0;
    while ((i < A->length) && (j < B->length))
    {
        if (A->A[i] == B->A[j])
        {
            C->A[k++] = A->A[i++];
            j++;
            C->length++;
        }
        else if (A->A[i] < B->A[j])
        {
            i++;
        }
        else if (A->A[i] > B->A[j])
        {
            j++;
        }
    }
}

void difference_array(const Array *A, const Array *B, Array *C)
{
    /* O(n^2) */
    C->length = 0;
    int k = 0;
    for (int i = 0; i < A->length; i++)
    {
        int is_found = 0;
        for (int j = 0; (j < B->length) && (!is_found); j++)
        {
            if (A->A[i] == B->A[j])
            {
                is_found = 1;
            }
        }
        if (!is_found)
        {
            C->A[k++] = A->A[i];
            C->length++;
        }
    }
}

void difference_array_sorted(const Array *A, const Array *B, Array *C)
{
    /* O(n) */
    int i = 0;
    int j = 0;
    int k = 0;
    C->length = 0;
    while (i < A->length)
    {
        if (A->A[i] == B->A[j])
        {
            i++;
            j++;
        }
        else if (A->A[i] < B->A[j])
        {
            C->A[k++] = A->A[i++];
            C->length++;
        }
        else if (A->A[i] > B->A[j])
        {
            j++;
        }
    }
    while (i < A->length)
    {
        C->A[k++] = A->A[i++];
        C->length++;
    }
    
}

int main()
{
    Array arr = {
        .A = {2, 3, 4, 5, 6},
        .size = 20,
        .length = 5};

    display_array(&arr);
    append(&arr, 10);
    display_array(&arr);
    insert(&arr, 4, 12);
    display_array(&arr);
    int x = delete_element(&arr, 4);
    printf("deleted: %d\n", x);
    display_array(&arr);
    x = delete_element(&arr, 0);
    printf("deleted: %d\n", x);
    display_array(&arr);
    printf("Linear Search 12 index %d\n", linear_search(&arr, 12));
    printf("Linear Search 6 index: %d\n", linear_search(&arr, 6));
    printf("Binary Search 6 index: %d\n", binary_search(&arr, 6));
    printf("Binary Search 12 index: %d\n", binary_search(&arr, 12));
    printf("Binary Search Recursive: 6 index: %d\n", binary_search_recursive(&arr, 0, arr.length - 1, 6));
    printf("Binary Search Recursive: 12 index: %d\n", binary_search_recursive(&arr, 0, arr.length - 1, 12));

    set(&arr, 0, 5);
    display_array(&arr);
    printf("GET 3: %d\n", get(&arr, 3));
    printf("Max: %d\n", get_max(&arr));
    printf("Min: %d\n", get_min(&arr));
    printf("Sum: %d\n", get_sum(&arr));
    printf("Sum recursive: %d\n", get_sum_recursive(&arr, arr.length - 1));
    printf("Avg: %.2lf\n", get_average(&arr));
    reverse(&arr);
    display_array(&arr);
    append(&arr, 12);
    reverse_swap(&arr);
    display_array(&arr);
    printf("Is sorted: %d\n", is_sorted(&arr));
    Array A = {
        .A = {2, 5, 7, 8},
        .length = 4,
        .size = 16};

    Array B = {
        .A = {1, 3, 4, 6, 9, 16, 17, 18, 19},
        .length = 9,
        .size = 36};

    Array D = {
        .A = {0},
        .length = 100,
        .size = 400};
    display_array(&B);
    printf("Is sorted: %d\n", is_sorted(&B));
    insert_sorted(&B, 9);
    display_array(&B);
    printf("Is sorted: %d\n", is_sorted(&B));

    Array C = {
        .A = {2, -3, 25, 10, -15, -7},
        .length = 6,
        .size = 24,
    };

    display_array(&C);
    rearrange(&C);
    display_array(&C);

    display_array(&A);
    display_array(&B);
    merge_array(&A, &B, &C);
    display_array(&C);

    Array a = {
        .A = {3, 4, 5, 6, 10},
        .length = 5,
        .size = 20};

    Array b = {
        .A = {2, 4, 5, 7, 12},
        .length = 5,
        .size = 20,
    };

    Array c = {
        .A = {0},
        .length = 0,
        .size = 0};

    Array a2 = {
        .A = {3, 5, 10, 4, 6},
        .length = 5,
        .size = 20};

    Array b2 = {
        .A = {12, 4, 7, 2, 5},
        .length = 5,
        .size = 20};

    Array c2 = {
        .A = {0},
        .length = 0,
        .size = 0};

    union_array(&a2, &b2, &c2);
    display_array(&c2);
    union_array_sorted(&a, &b, &c);
    display_array(&c);
    intersection_array(&a2, &b2, &c2);
    display_array(&c2);
    intersection_array_sorted(&a, &b, &c);
    display_array(&c);
    difference_array(&a2, &b2, &c2);
    display_array(&c2);
    difference_array_sorted(&a, &b, &c);
    display_array(&c);

    return 0;
}
