#include <stdio.h>
#include <stdlib.h>

int func(int n)
{
    if (n > 100)
    {
        return (n - 10);
    }
    else
    {
        return (func(func(n + 11)));
    }
    
}

int main()
{
    printf("%d\n", func(95));
    return 0;
}