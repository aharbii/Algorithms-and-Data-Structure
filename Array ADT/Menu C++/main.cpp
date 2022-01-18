#include <iostream>

using namespace std;

class Array
{
private:
    int A[100];
    int size;
    int length;

public:
    Array()
    {
        size = 10;
        length = 0;
    }
    Array(int sz)
    {
        size = sz;
        length = 0;
    }
    ~Array()
    {
    }

    void display_array()
    {
        /* O(n) */
        printf("Elements are: ");
        for (int i = 0; i < length; i++)
        {
            printf("%2d ", A[i]);
        }
        printf("\n");
    }

    void append(int x)
    {
        /* O(1) */
        if (length < size)
        {
            A[length] = x;
            length++;
        }
    }

    void insert(int index, int value)
    {
        /* O(n) */
        if ((index >= 0) && (index <= length))
        {
            for (int i = length; i > index; i--)
            {
                A[i] = A[i - 1];
            }
            A[index] = value;
            length++;
        }
    }

    int delete_element(int index)
    {
        /* O(n) */
        int x = 0;
        if ((index >= 0) && (index <= length))
        {
            x = A[index];
            A[index] = 0;
            for (int i = index; i < (length - 1); i++)
            {
                A[i] = A[i + 1];
            }
            length--;
            return x;
        }
        return 0;
    }

    int linear_search(int key)
    {
        /* O(n) */
        for (int i = 0; i < length; i++)
        {
            if (key == A[i])
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

    int improved_linear_search(int key)
    {
        /* O(n) */
        for (int i = 0; i < length; i++)
        {
            if (key == A[i])
            {
                swap(&A[i], &A[0]);
                return i;
            }
        }
        return -1;
    }

    int binary_search(int key)
    {
        /* O(log(n)) */
        int l = 0;
        int h = length - 1;
        while ((l <= h))
        {
            int mid = (h + l) / 2;
            if (A[mid] == key)
            {
                return mid;
            }
            else if (A[mid] > key)
            {
                h = mid - 1;
            }
            else if (A[mid] < key)
            {
                l = mid + 1;
            }
        }
        return -1;
    }

    int binary_search_recursive(int l, int h, int key)
    {
        /* O(log(n)) */
        if (l <= h)
        {
            int mid = (l + h) / 2;
            if (A[mid] == key)
            {
                return mid;
            }
            else if (A[mid] > key)
            {
                return binary_search_recursive(l, mid - 1, key);
            }
            else if (A[mid] < key)
            {
                return binary_search_recursive(mid + 1, h, key);
            }
        }
        return -1;
    }

    int get(int index)
    {
        /* O(1) */
        if ((index >= 0) && (index <= length))
        {
            return A[index];
        }
        return -1;
    }

    void set(int index, int key)
    {
        /* O(1) */
        if ((index >= 0) && (index <= length))
        {
            A[index] = key;
        }
    }

    int get_max()
    {
        /* O(n) */
        int max = A[0];
        for (int i = 1; i < length; i++)
        {
            if (max < A[i])
            {
                max = A[i];
            }
        }
        return max;
    }

    int get_min()
    {
        /* O(n) */
        int min = A[0];
        for (int i = 0; i < length; i++)
        {
            if (min > A[i])
            {
                min = A[i];
            }
        }
        return min;
    }

    int get_sum()
    {
        /* O(n) */
        int sum = 0;
        for (int i = 0; i < length; i++)
        {
            sum += A[i];
        }
        return sum;
    }

    int get_sum_recursive(int n)
    {
        /* O(n) */
        if (n < 0)
        {
            return 0;
        }

        return A[n] + get_sum_recursive(n - 1);
    }

    double get_average()
    {
        /* O(n) */
        int total = 0;
        for (int i = 0; i < length; i++)
        {
            total += A[i];
        }

        double average = (double)total / length;
        return average;
    }

    void reverse()
    {
        /* O(n) */
        Array B(length);
        for (int i = (length - 1), j = 0; i >= 0; i--, j++)
        {
            B.A[j] = A[i];
        }

        for (int i = 0; i < length; i++)
        {
            A[i] = B.A[i];
        }
    }

    void reverse_swap()
    {
        /* O(n) */
        for (int i = 0, j = (length - 1); i < j; i++, j--)
        {
            swap(&A[i], &A[j]);
        }
    }

    void insert_sorted(int value)
    {
        /* O(n) */
        int i = length - 1;
        while ((A[i] > value) && (i >= 0))
        {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = value;
        length++;
    }

    int is_sorted()
    {
        /* O(n) */
        for (int i = 0; i < (length - 1); i++)
        {
            if (A[i] > A[i + 1])
            {
                return 0;
            }
        }
        return 1;
    }

    void rearrange()
    {
        int i = 0;
        int j = length - 1;
        while (i < j)
        {
            while (A[i] < 0)
            {
                i++;
            }
            while (A[j] >= 0)
            {
                j--;
            }
            if (i < j)
            {
                swap(&A[i], &A[j]);
            }
        }
    }

    void merge_array(const Array *B, Array *C)
    {
        /* O(m + n) */
        int i = 0;
        int j = 0;
        int k = 0;
        while ((i < length) && (j < B->length))
        {
            if (A[i] < B->A[j])
            {
                C->A[k++] = A[i++];
            }
            else
            {
                C->A[k++] = B->A[j++];
            }
        }

        while (i < length)
        {
            C->A[k++] = A[i++];
        }
        while (j < B->length)
        {
            C->A[k++] = B->A[j++];
        }
        C->length = k;
        C->size = k * sizeof(int);
    }

    void union_array(const Array *B, Array *C)
    {
        /* O(n^2) */
        int i = 0;
        int j = 0;
        int k = 0;
        C->length = 0;
        for (int i = 0; i < length; i++)
        {
            C->A[k++] = A[i];
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

    void union_array_sorted(const Array *B, Array *C)
    {
        /* O(n^2) */
        int i = 0;
        int j = 0;
        int k = 0;
        C->length = 0;
        while ((i < length) && (j < B->length))
        {
            if (A[i] < B->A[j])
            {
                C->A[k++] = A[i++];
                C->length++;
            }
            else if (A[i] == B->A[j])
            {
                C->A[k++] = B->A[i++];
                j++;
                C->length++;
            }
            else if (A[i] > B->A[j])
            {
                C->A[k++] = B->A[j++];
                C->length++;
            }
        }

        while (i < length)
        {
            C->A[k++] = A[i++];
            C->length++;
        }
        while (j < B->length)
        {
            C->A[k++] = B->A[j++];
            C->length++;
        }
    }

    void intersection_array(const Array *B, Array *C)
    {
        /* O(n^2) */
        C->length = 0;
        int k = 0;
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < B->length; j++)
            {
                if (A[i] == B->A[j])
                {
                    C->A[k++] = A[i];
                    C->length++;
                }
            }
        }
    }

    void intersection_array_sorted(const Array *B, Array *C)
    {
        /* O(n) */
        int i = 0;
        int j = 0;
        int k = 0;
        C->length = 0;
        while ((i < length) && (j < B->length))
        {
            if (A[i] == B->A[j])
            {
                C->A[k++] = A[i++];
                j++;
                C->length++;
            }
            else if (A[i] < B->A[j])
            {
                i++;
            }
            else if (A[i] > B->A[j])
            {
                j++;
            }
        }
    }

    void difference_array(const Array *B, Array *C)
    {
        /* O(n^2) */
        C->length = 0;
        int k = 0;
        for (int i = 0; i < length; i++)
        {
            int is_found = 0;
            for (int j = 0; (j < B->length) && (!is_found); j++)
            {
                if (A[i] == B->A[j])
                {
                    is_found = 1;
                }
            }
            if (!is_found)
            {
                C->A[k++] = A[i];
                C->length++;
            }
        }
    }

    void difference_array_sorted(const Array *B, Array *C)
    {
        /* O(n) */
        int i = 0;
        int j = 0;
        int k = 0;
        C->length = 0;
        while (i < length)
        {
            if (A[i] == B->A[j])
            {
                i++;
                j++;
            }
            else if (A[i] < B->A[j])
            {
                C->A[k++] = A[i++];
                C->length++;
            }
            else if (A[i] > B->A[j])
            {
                j++;
            }
        }
        while (i < length)
        {
            C->A[k++] = A[i++];
            C->length++;
        }
    }
};

int main()
{
    int sz;
    printf("Enter size of Array: ");
    scanf("%d", &sz);
    Array arr1(sz);

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
            arr1.insert(index, x);
            break;

        case 2:
            printf("Enter index: ");
            scanf("%d", &index);
            x = arr1.delete_element(index);
            printf("Deleted Element is: %d\n", x);
            break;

        case 3:
            printf("Enter element to search: ");
            scanf("%d", &x);
            index = arr1.linear_search(x);
            printf("Element index: %d\n", index);
            break;

        case 4:
            printf("Sum is %d\n", arr1.get_sum());
            break;

        case 5:
            arr1.display_array();
            break;

        default:
            break;
        }
    } while (ch < 6);
    return 0;
}
