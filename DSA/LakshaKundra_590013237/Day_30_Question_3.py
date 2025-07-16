def count_set_bits(n):
    count = 0
    while n:
        n = n & (n - 1)
        count += 1
    return count

print(count_set_bits(7))
print(count_set_bits(9))
