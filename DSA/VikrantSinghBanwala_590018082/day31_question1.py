def is_power_of_two(n):
    return n > 0 and (n & (n - 1)) == 0
number1 = 8
number2 = 10
print(f"{number1} is a power of two: {is_power_of_two(number1)}")
print(f"{number2} is a power of two: {is_power_of_two(number2)}") 