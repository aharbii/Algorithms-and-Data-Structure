#include <stdio.h>
#include <stdlib.h>

double e(int x, int n)
{
    /* O(n^2) */
    static double p = 1;
    static double f = 1;
    if (n == 0)
    {
        return 1;
    }
    double r = e(x, n - 1);
    p *= x;
    f *= n;
    return (r + (p / f));
}

int main()
{
    printf("e = %lf\n", e(4, 10));

    return 0;
}