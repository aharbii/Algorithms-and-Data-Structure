def funcA(n):
    if (n > 0):
        print(n)
        funcB(n - 1)


def funcB(n):
    if(n > 1):
        print(n)
        funcA(int(n / 2))


funcA(20)
