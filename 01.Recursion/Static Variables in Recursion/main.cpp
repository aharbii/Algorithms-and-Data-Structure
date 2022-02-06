#include <iostream>

int func(int n)
{
    if (n > 0)
    {
        return (func(n - 1) + n);
    }
    return 0;
}

int func_static(int n)
{
    static int x = 0;
    if (n > 0)
    {
        x++;
        return (func_static(n - 1) + x);
    }
    return 0;
    
}

int main()
{
    int a = 5;
    std::cout << "Recursion: " << func(a) << std::endl;
    std::cout << "Static Recursion: " << func_static(a) << std::endl;
    return 0;
}