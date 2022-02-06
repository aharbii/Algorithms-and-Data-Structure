def func(n):
    if (n > 0):
        func(n - 1)
        print(n)

x = 3
func(x)