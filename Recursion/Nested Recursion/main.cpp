#include <iostream>

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
    std::cout << func(95) << std::endl;
    return 0;
}