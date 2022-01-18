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
    Array arr1 = {
        .A = {0},
        .length = 0,
        .size = 0
    };
    printf("Enter size of Array: ");
    scanf("%d", &arr1.size);

    int ch;

    int index;
    int x;
    do
    {    
        printf("\nMenu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) 
        {
            case 1:
                printf("Enter an element and index: ");
                scanf("%d%d", &x, &index);
                insert(&arr1, index, x);
                break;

            case 2:
                printf("Enter index: ");
                scanf("%d", &index);
                x = delete_element(&arr1, index);
                printf("Deleted Element is: %d\n", x);
                break;

            case 3:
                printf("Enter element to search: ");
                scanf("%d", &x);      
                index = linear_search(&arr1, x);
                printf("Element index: %d\n", index);
                break;

            case 4:
                printf("Sum is %d\n", get_sum(&arr1));
                break;

            case 5:
                display_array(&arr1);
                break;
                
            default:
                break;
        }
    } while(ch < 6);
    return 0;
}
