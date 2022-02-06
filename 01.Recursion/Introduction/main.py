def func(n):
    if (n > 0):
        print(n)
        func(n - 1)

x = 3
func(x)