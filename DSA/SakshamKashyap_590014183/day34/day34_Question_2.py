def subtract_one(n):
    a = 1
    while not (n & a):
        n = n ^ a
        a <<= 1
    n = n ^ a
    return n

print(subtract_one(5))
print(subtract_one(8))