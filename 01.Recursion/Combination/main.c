#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
{
    if (n < 1)
    {
        return 1;
    }
    return (n * factorial(n - 1));
}

int combination(int n, int r)
{
    /* O(n) */
    int t0 = factorial(n);
    int t1 = factorial(r);
    int t2 = factorial(n - r);

    return (t0 / (t1 * t2));
}

int combination_recursion(int n, int r)
{
    if (n == r)
    {
        return 1;
    }

    if (r == 0)
    {
        return 1;
    }

    return (combination_recursion(n - 1, r) + combination_recursion(n - 1, r - 1));
    
}

int main()
{
    printf("%d\n", combination(4, 2));
    printf("%d\n", combination_recursion(4, 2));

    return 0;
}