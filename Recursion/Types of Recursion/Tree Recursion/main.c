#include <stdio.h>
#include <stdlib.h>

void func(int n)
{
    if (n > 0)
    {
        printf("%d\n", n);
        func(n - 1);
        func(n - 1);
    }
    
}

int main()
{
    func(3);
    return 0;
}