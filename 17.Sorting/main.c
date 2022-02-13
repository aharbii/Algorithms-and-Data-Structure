#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void print_array(int *array_ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array_ptr[i]);
    }
    printf("\n");
}

/* ========================================================================================================== */

/* =============== Bubble Sort =================== */

void bubble_sort(int *array_ptr, int size)
{
    /* O(n^2) */
    /* Adaptive */
    int is_not_sorted = 1;

    for (int i = 1; (i < size) && (is_not_sorted); i++)
    {
        is_not_sorted = 0;

        for (int j = 0; j < (size - i); j++)
        {
            if (array_ptr[j] > array_ptr[j + 1])
            {
                swap(&array_ptr[j], &array_ptr[j + 1]);
                is_not_sorted = 1;
            }
        }
    }
}

/* ========================================================================================================== */

/* =============== Insertion Sort =================== */

void insert_sorted(int *array_ptr, int size, int key)
{
    int j = size - 1;
    while ((array_ptr[j] > key) && (j >= 0))
    {
        array_ptr[j + 1] = array_ptr[j];
        j--;
    }
    array_ptr[j + 1] = key;
}

void insertion_sort(int *array_ptr, int size)
{
    /* O(n^2) */
    /* Adaptive */
    /* Good for Linked List */
    for (int i = 1; i < size; i++)
    {
        int key = array_ptr[i];
        insert_sorted(array_ptr, i, key);
    }
}

/* ========================================================================================================== */

/* =============== Selection Sort =================== */

int get_max_index(int *array_ptr, int size)
{
    int max_idx = 0;
    for (int j = 0; j < size; j++)
    {
        if (array_ptr[max_idx] < array_ptr[j])
        {
            max_idx = j;
        }
    }
    return max_idx;
}

void selection_sort(int *array_ptr, int size)
{
    /* O(n^2) */
    /* Not Adaptive */
    /* Good for less number of swaps */
    for (int i = 0; i < size; i++)
    {
        int max_idx = get_max_index(array_ptr, size - i);
        swap(&array_ptr[size - i - 1], &array_ptr[max_idx]);
    }
}

/* ========================================================================================================== */

/* =============== Quick Sort =================== */

void partition(int *array_ptr, int first, int last)
{
    if (last <= first)
    {
        return; // Base condition to end recursion
    }

    int pivot = first;
    int i = first + 1;
    int j = last;
    while (i < j)
    {
        while (array_ptr[i] <= array_ptr[pivot])
        {
            i++; // Increment i till reach larger element than pivot
        }

        while (array_ptr[j] > array_ptr[pivot])
        {
            j--; // Decrement j till reach smaller element than pivot
        }

        if ((i < j) && (array_ptr[i] > array_ptr[j]))
        {
            swap(&array_ptr[i], &array_ptr[j]); // Swapping only if A[i] is greater than A[j]
        }
    }
    if (array_ptr[pivot] > array_ptr[j])
    {
        swap(&array_ptr[pivot], &array_ptr[j]); // Setting pivot to its sorted position
        pivot = j;                              // update pivot index for upcoming calls.
    }

    partition(array_ptr, pivot + 1, last);  // recall quick sort to partition after pivot
    partition(array_ptr, first, pivot - 1); // recall quick sort to partition before pivot
}

void quick_sort(int *array_ptr, int size) // Just array_ptr call declaration in the same format of other sorting functions.
{
    /* O(nlog(n)) */
    /* O(n^2) --> Only if the array_ptr is sorted */
    partition(array_ptr, 0, size - 1);
}

/* =============== Another Implementation =================== */

int partition_second(int *array_ptr, int l, int h)
{
    int pivot = array_ptr[l];
    int i = l;
    int j = h;
    do
    {
        do
        {
            i++;
        } while (array_ptr[i] <= pivot);

        do
        {
            j--;
        } while (array_ptr[j] > pivot);

        if (i < j)
        {
            swap(&array_ptr[i], &array_ptr[j]);
        }

    } while (i < j);
    swap(&array_ptr[l], &array_ptr[j]);
    return j;
}

void quick_sort_two(int *array_ptr, int l, int h)
{
    int j = 0;
    if (l < h)
    {
        j = partition_second(array_ptr, l, h);
        quick_sort_two(array_ptr, l, j);
        quick_sort_two(array_ptr, j + 1, h);
    }
}

/* ========================================================================================================== */

/* =============== Merge Sort =================== */

void merge(int *array_ptr, int l, int mid, int h)
{
    int *sorted = (int *)malloc((h - l + 1) * sizeof(int));
    int i = l;
    int j = mid + 1;
    int k = l;
    while ((i <= mid) && (j <= h))
    {
        if (array_ptr[i] < array_ptr[j])
        {
            sorted[k++] = array_ptr[i++];
        }
        else
        {
            sorted[k++] = array_ptr[j++];
        }
    }

    while (i <= mid)
    {
        sorted[k++] = array_ptr[i++];
    }

    while (j <= h)
    {
        sorted[k++] = array_ptr[j++];
    }

    for (int i = l; i <= h; i++)
    {
        array_ptr[i] = sorted[i];
    }

    free(sorted);
}

void merge_sort(int *array_ptr, int size)
{
    /* O(nlog(n)) */
    /* Requires Extra Space */
    int p = 0;
    for (p = 2; p <= size; p *= 2)
    {
        for (int i = 0; (i + p - 1) < size; i += p)
        {
            int l = i;
            int h = i + p - 1;
            int mid = (l + h) / 2;
            merge(array_ptr, l, mid, h);
        }
    }
    if ((p / 2) < size)
    {
        merge(array_ptr, 0, (p / 2) - 1, (size - 1));
    }
}

/* =============== Another Implementation =================== */

void merge_sort_two(int *array_ptr, int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        merge_sort_two(array_ptr, l, mid);
        merge_sort_two(array_ptr, mid + 1, h);
        merge(array_ptr, l, mid, h);
    }
}

/* ========================================================================================================== */

/* =============== Count Sort =================== */

void get_max_min(int *array_ptr, int size, int *max, int *min)
{
    *max = array_ptr[0];
    *min = array_ptr[0];
    for (int i = 1; i < size; i++)
    {
        if (array_ptr[i] > *max)
        {
            *max = array_ptr[i];
        }

        if (array_ptr[i] < *min)
        {
            *min = array_ptr[i];
        }
    }
}

void count_sort(int *array_ptr, int size)
{
    /* O(n) */
    /* Not good if elements constrains has wide set of numbers due to memeory leak */
    /* Otherwise, It's perfect */
    int max = 0;
    int min = 0;
    get_max_min(array_ptr, size, &max, &min);
    int *count_table = (int *)calloc(max - min + 1, sizeof(int));

    for (int i = 0; i < size; i++)
    {
        count_table[array_ptr[i] - min] += 1;
    }

    int k = 0;
    for (int i = 0; i < (max - min + 1); i++)
    {
        while (count_table[i] > 0)
        {
            array_ptr[k++] = i + min;
            count_table[i] -= 1;
        }
    }
}

/* ========================================================================================================== */

/* =============== Bucket Sort =================== */

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void append_nodes(Node **p, int key)
{
    Node *t = (Node *)malloc(sizeof(Node));
    t->data = key;
    t->next = NULL;
    if (*p == NULL)
    {
        *p = t;
    }
    else
    {
        t->next = *p;
        *p = t;
    }
}

int delete_node(Node **p)
{
    Node *q = NULL;
    int x = 0;
    q = (*p);
    x = q->data;
    (*p) = (*p)->next;
    free(q);
    return x;
}

void bucket_sort(int *array_ptr, int size)
{
    /* O(n) */
    int max = 0;
    int min = 0;
    get_max_min(array_ptr, size, &max, &min);
    Node **sorted = (Node **)malloc(max - min + 1 * sizeof(Node *));
    for (int i = 0; i < (max - min + 1); i++)
    {
        sorted[i] = NULL;
    }

    for (int i = 0; i < size; i++)
    {
        append_nodes(&sorted[array_ptr[i] - min], array_ptr[i]);
    }

    int k = 0;
    for (int i = 0; i < (max - min + 1); i++)
    {
        Node *p = sorted[i];
        while (p != NULL)
        {
            array_ptr[k++] = delete_node(&p);
        }
    }
    free(sorted);
}

/* ========================================================================================================== */

/* =============== Radix Sort =================== */

int count_digits(int num)
{
    int digits = 0;
    while (num > 0)
    {
        digits += 1;
        num /= 10;
    }
    return digits;
}

void radix_sort(int *array_ptr, int size)
{
    int bucket[10][10];
    int bucket_count[10];
    int passes = 0;

    int max = 0;
    int min = 0;
    get_max_min(array_ptr, size, &max, &min);
    while (max > 0)
    {
        passes++;
        max /= 10;
    }

    int base = 1;
    for (int pass = 0; pass < passes; pass++)
    {
        for (int i = 0; i < 10; i++)
        {
            bucket_count[i] = 0;
        }
        for (int i = 0; i < size; i++)
        {
            int remainder = (array_ptr[i] / base) % 10;
            bucket[remainder][bucket_count[remainder]] = array_ptr[i];
            bucket_count[remainder] += 1;
        }

        int i = 0;
        for (int k = 0; k < 10; k++)
        {
            for (int j = 0; j < bucket_count[k]; j++)
            {
                array_ptr[i] = bucket[k][j];
                i++;
            }
        }
        base *= 10;
    }
}

/* ========================================================================================================== */

/* =============== Shell Sort =================== */

void shell_sort(int *array_ptr, int size)
{
    /* O(nlog(n)) */
    int gab = size / 2;
    while (gab > 0)
    {
        int i = 0;
        int j = gab;
        while (j < size)
        {
            if (array_ptr[i] > array_ptr[j])
            {
                swap(&array_ptr[i], &array_ptr[j]); // Insert j element
            }
            
            // Used to compare previous elements with the new sorted one
            int new_j = i;  
            int new_i = i - gab;

            // Updating i and j for the next iteration
            i++;
            j++;

            // Checking all previous elements with the same gab and sort them
            while (new_i >= 0)
            {
                if (array_ptr[new_i] > array_ptr[new_j])
                {
                    swap(&array_ptr[new_i], &array_ptr[new_j]);
                }
                new_j = new_i;
                new_i -= gab;
            }
        }
        gab /= 2;
    }
}

/* =============== Another Implementation =================== */

void shell_sort_two(int *array_ptr, int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i++)
        {
            for (int j = i - gap; (j >= 0) && (array_ptr[j] > array_ptr[j + gap]); j -= gap)
            {
                swap(&array_ptr[j], &array_ptr[j + gap]);
            }
        }
    }
}
/* ========================================================================================================== */

/* =============== Heap Sort =================== */
        /* Implemented in Heap program in section 16 */

/* ========================================================================================================== */

int main()
{
    int array_ptr[] = {9, 5, 16, 8, 13, 6, 12, 10, 4, 2, 3};
    shell_sort(array_ptr, ARRAY_SIZE(array_ptr));
    print_array(array_ptr, ARRAY_SIZE(array_ptr));
    return 0;
}