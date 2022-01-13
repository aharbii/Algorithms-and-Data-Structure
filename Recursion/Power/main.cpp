#include <iostream>

int power(int base, int exponent)
{
    if (exponent == 0)
    {
        return 1;
    }
    return (base * power(base, exponent - 1));
}

int power_half(int base, int exponent)
{
    if (exponent == 0)
    {
        return 1;
    }
    if ((exponent % 2) == 0)
    {
        return (power_half(base * base, exponent / 2));
    }
    return (base * power_half(base * base, (exponent - 1) / 2));
}

int main()
{
    std::cout << power(2, 5) << std::endl;
    std::cout << power_half(2, 30) << std::endl;
}