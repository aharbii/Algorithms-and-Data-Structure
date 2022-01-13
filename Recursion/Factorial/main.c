#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
{
    /* O(n) */
    if (n < 1)
    {
        return 1;
    }
    return (n * factorial(n - 1));
    
}

int main()
{
    int x = 6;
    int fact = factorial(x);
    printf("%d\n", fact);
    return 0;
}