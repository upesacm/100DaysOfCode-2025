def toggle_ith_bit(n,i):
    mask = 1 << i
    return n ^ mask

#example
print(toggle_ith_bit(5,2))