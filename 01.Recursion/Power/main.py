def power(base, exponent):
    if (exponent == 0):
        return 1
    return base * (power(base, exponent - 1))

def power_half(base, exponent):
    if (exponent == 0):
        return 1
    if ((exponent % 2) == 0):
        return (power_half(base * base, exponent / 2))
    return (base * power_half(base * base, (exponent - 1) / 2))

print(power(2, 5))
print(power_half(2, 30))
