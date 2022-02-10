#include <stdio.h>
#include <stdlib.h>

typedef struct MinHeap
{
    int size;
    int n;
    int *data;
} MinHeap;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heap_insert(MinHeap *h, int key)
{
    /* O(log(n)) */
    h->size += 1;
    h->data = (int *)realloc(h->data, h->size * sizeof(int));
    h->data[h->size - 1] = key;
    int i = h->size;
    while (i > 1 && (h->data[i - 1] < h->data[(i / 2) - 1]))
    {
        swap(&h->data[i - 1], &h->data[(i / 2) - 1]);
        i = i / 2;
    }
}

void heap_create(MinHeap *h, int *array, int size)
{
    /* O(nlog(n)) */
    h->size = 0;
    h->n = size;
    h->data = (int *)malloc(h->size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        heap_insert(h, array[i]);
    }
}

void heap_display(MinHeap h)
{
    /* O(n) */
    for (int i = 0; i < h.size; i++)
    {
        printf("%d ", h.data[i]);
    }
    printf("\n");
}

int heap_delete(MinHeap *h)
{
    int x = h->data[0];
    h->data[0] = h->data[h->size - 1];
    int i = 1;
    int j = i * 2;
    while (j < h->size)
    {
        if (h->data[j] < h->data[j - 1])
        {
            j += 1;
        }

        if (h->data[i - 1] > h->data[j - 1])
        {
            swap(&h->data[i - 1], &h->data[j - 1]);
            i = j;
            j = i * 2;
        }
        else
        {
            break;
        }
    }
    h->size -= 1;
    h->data[h->size] = x;
    return x;
}

void heap_sort(MinHeap *h, int *array, int size)
{
    heap_create(h, array, size);
    for (int i = 0; i < h->n; i++)
    {
        heap_delete(h);
    }
}

void heap_sort_display(MinHeap h)
{
    for (int i = 0; i < h.n; i++)
    {
        printf("%d ", h.data[i]);
    }
    printf("\n");
}

void heapify(MinHeap *h, int *array, int size)
{
    /* O(n) */
    h->size = size;
    h->n = size;
    h->data = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        h->data[i] = array[i];
    }

    for (int i = h->size; i > 0; i--)
    {
        int root = i;
        int left_child = (root * 2) - 1;
        int right_child = (root * 2);

        while (right_child < h->size)
        {
            if (h->data[right_child] < h->data[left_child])
            {
                if (h->data[right_child] < h->data[root - 1])
                {
                    swap(&h->data[right_child], &h->data[root - 1]);
                    root = right_child + 1;
                    left_child = (root * 2) - 1;
                    right_child = (root * 2);
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (h->data[left_child] < h->data[root - 1])
                {
                    swap(&h->data[left_child], &h->data[root - 1]);
                    root = left_child + 1;
                    left_child = (root * 2) - 1;
                    right_child = (root * 2);
                }
                else
                {
                    break;
                }
            }
        }
    }
}

int main()
{
    MinHeap h;
    int nums[] = {30, 18, 25, 20, 12, 15, 5};
    int size = sizeof(nums) / sizeof(nums[0]);
    heapify(&h, nums, size);
    heap_display(h);

    return 0;
}
