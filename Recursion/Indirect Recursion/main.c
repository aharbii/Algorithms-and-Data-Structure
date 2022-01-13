#include <stdio.h>
#include <stdlib.h>

void funcB(int n);

void funcA(int n)
{
    if (n > 0)
    {
        printf("%d\n", n);
        funcB(n - 1);
    }
    
}

void funcB(int n)
{
    if (n > 1)
    {
        printf("%d\n", n);
        funcA(n / 2);
    }
    
}

int main()
{
    funcA(20);
    return 0;
}