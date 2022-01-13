#include <iostream>

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
    std::cout << sum << std::endl;
    return 0;
}