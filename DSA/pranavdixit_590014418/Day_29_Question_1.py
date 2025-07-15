def isEvenOrOdd(n):
    if n & 1:
        return "Odd"
    else:
        return "Even"

# Sample Test
print(isEvenOrOdd(4))   # Output: Even
print(isEvenOrOdd(7))   # Output: Odd
