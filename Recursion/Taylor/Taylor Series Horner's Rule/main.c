#include <stdio.h>
#include <stdlib.h>

int e(int x, int n)
{
    /* O(n) */
    static int s = 1;
    if (n == 0)
    {
        return s;
    }
    s *= 1 + (x / n);
    return e(x, n - 1);
}

int main()
{
    printf("e = %d\n", e(4, 10));

    return 0;
}