def func(n):
    if (n > 0):
        return (func(n - 1) + n)
    return 0

def func_static(n):
    x = 0
    if (n > 0):
        x += 1
        return (func_static(n - 1) + x)
    return 0


a = 5
print(f"Recursion: {func(a)}")
print(f"Static Recursion: {func_static(a)}")