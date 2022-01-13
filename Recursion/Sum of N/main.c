#include <stdio.h>
#include <stdlib.h>

int sum_recursion(int n)
{
    if (n > 0)
    {
        return (n + sum_recursion(n - 1));
    }
    return 0;
    
}

int main()
{
    int x = 100;
    int sum = sum_recursion(x);
    printf("%d\n", sum);
    return 0;
}