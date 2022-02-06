#include <stdio.h>
#include <stdlib.h>

int e(int x, int n)
{
    /* O(n) */
    int s = 1;
    while (n > 0)
    {
        s *= 1 + (x / n);
        n--;
    }
    return s;
    
}

int main()
{
    printf("e = %d\n", e(4, 10));

    return 0;
}