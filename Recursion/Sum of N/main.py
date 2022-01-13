def sum_recursion(n):
    if (n > 0):
        return (n + sum_recursion(n - 1))
    return 0


x = 100
sum = sum_recursion(x)
print(sum)