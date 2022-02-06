#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n)
{
    /* O(2^n) */
    if (n == 1)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }

    return (fibonacci(n - 1) + fibonacci(n - 2));
}

int fibonacci_iter(int n)
{
    /* O(n) */
    int t0 = 0;
    int t1 = 1;
    if (n <= 1)
    {
        return n;
    }
    int s;
    for (int i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

/* Memoization */
int F[1000];
int fibonacci_memo(int n)
{
    /* O(n) */
    if (n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if (F[n - 2] == -1)
        {
            F[n - 2] = fibonacci_memo(n - 2);
        }
        if (F[n - 1] == -1)
        {
            F[n - 1] = fibonacci_memo(n - 1);
        }
    }

    return (F[n - 1] + F[n - 2]);
}

int main()
{
    for (int i = 0; i < 1000; i++)
    {
        F[i] = -1;
    }
    printf("%d\n", fibonacci_memo(1000));
    printf("%d\n", fibonacci_iter(1000));
    printf("%d\n", fibonacci(1000));
}