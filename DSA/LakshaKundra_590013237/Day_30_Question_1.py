def clear_ith_bit(n, i):
    mask = ~(1 << i)
    result = n & mask
    return result

print(clear_ith_bit(7, 1))
print(clear_ith_bit(10, 3))

