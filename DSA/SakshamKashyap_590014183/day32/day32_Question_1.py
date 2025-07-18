def swap_xor(a, b):
    print(f"Before Swap: a = {a}, b = {b}")
    a = a ^ b
    b = a ^ b
    a = a ^ b
    print(f"After Swap: a = {a}, b = {b}")
    return a, b

swap_xor(4, 7)
swap_xor(1, 2)
