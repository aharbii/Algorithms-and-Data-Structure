#include <iostream>

void func(int n)
{
    if (n > 0)
    {
        std::cout << n << std::endl;
        func(n - 1);
    }
    
}

int main()
{
    int x = 3;
    func(x);
    return 0;
}