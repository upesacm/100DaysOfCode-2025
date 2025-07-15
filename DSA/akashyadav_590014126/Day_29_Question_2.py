def get_i_bit(n, i):
    # shifting number by ith position and then checking it with and operator
    return 1 if (n & (1 << i)) != 0 else 0

#example
print(get_i_bit(5, 2))  #Output: 1