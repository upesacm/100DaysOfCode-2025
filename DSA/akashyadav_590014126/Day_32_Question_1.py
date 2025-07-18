def swap_xor(a,b):
    a=a^b
    b=a^b
    a=a^b
    print(f"after swap:a={a} , b={b}")
    return a,b

print(swap_xor(78,99))