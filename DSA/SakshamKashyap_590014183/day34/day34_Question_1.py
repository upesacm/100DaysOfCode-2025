def ADD_ONE(n):
    a = 1
    while a&n:
        n = n ^ a
        a <<= 1
    n = n ^ a
    return n
print(ADD_ONE(4))
print(ADD_ONE(7))
