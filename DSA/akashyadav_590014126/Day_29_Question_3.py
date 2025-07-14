def set_i_bit(n, i):
    return n | (1 << i)

#example
print(set_i_bit(8, 2))  # Output: 12