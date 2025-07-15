def setIthBit(n, i):
    return n | (1 << i)

# Sample Test
print(setIthBit(5, 1))   # Output: 7 (binary 101 → set 1st bit → 111)
print(setIthBit(8, 2))   # Output: 12 (binary 1000 → set 2nd bit → 1100)
