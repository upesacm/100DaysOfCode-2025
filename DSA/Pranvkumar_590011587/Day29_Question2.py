def get_ith_bit(n, i):
    if n & (1 << i):
        return 1
    else:
        return 0

# Example usage
print(get_ith_bit(5, 0))  
print(get_ith_bit(5, 1))
