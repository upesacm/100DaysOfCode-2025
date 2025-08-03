def toggle_ith_bit(n, i):
    return n ^ (1 << i)

print(toggle_ith_bit(10, 1))
print(toggle_ith_bit(5, 2))
