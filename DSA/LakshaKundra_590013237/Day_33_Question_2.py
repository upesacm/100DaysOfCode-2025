def turn_off_rightmost_set_bit(n):
    return n & (n - 1)

print(turn_off_rightmost_set_bit(12))
print(turn_off_rightmost_set_bit(10))
