def turn_off_rightmost_set_bit(n):
    if n == 0:
        return 0
    new_number = n & (n - 1)
    return new_number
