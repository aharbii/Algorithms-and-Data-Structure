#include <iostream>

void func(int n)
{
    if (n > 0)
    {
        func(n - 1);
        std::cout << n << std::endl;
    }
    
}

int main()
{
    int x = 3;
    func(x);
    return 0;
}