def isolate_rightmost_set_bit(n):
    return n & -n

print(isolate_rightmost_set_bit(10))
print(isolate_rightmost_set_bit(12))
