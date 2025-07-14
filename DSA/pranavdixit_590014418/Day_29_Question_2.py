def getIthBit(n, i):
    if n & (1 << i):
        return 1
    else:
        return 0

# Sample Test
print(getIthBit(5, 0))  # Output: 1 (binary 101, 0th bit is 1)
print(getIthBit(5, 1))  # Output: 0 (binary 101, 1st bit is 0)
