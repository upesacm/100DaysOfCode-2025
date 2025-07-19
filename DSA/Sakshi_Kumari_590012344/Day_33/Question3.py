def isolate_rightmost_set_bit(n):
    if n == 0:
        return 0
    return n & -n
