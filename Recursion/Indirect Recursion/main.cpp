#include <iostream>

void funcB(int n);

void funcA(int n)
{
    if (n > 0)
    {
        std::cout << n << std::endl;
        funcB(n - 1);
    }
}

void funcB(int n)
{
    if (n > 1)
    {
        std::cout << n << std::endl;
        funcA(n / 2);
    }
}

int main()
{
    funcA(20);
    return 0;
}