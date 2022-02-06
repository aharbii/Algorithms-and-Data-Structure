#include <stdio.h>
#include <stdlib.h>

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
    printf("%d\n", power(2, 5));
    printf("%d\n", power_half(2, 30));
}