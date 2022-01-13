#include <iostream>

int factorial(int n)
{
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
    std::cout << fact << std::endl;
    return 0;
}