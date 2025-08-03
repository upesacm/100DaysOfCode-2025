def subtract_one(n):
    m = 1
    while not (n & m):
        n = n ^ m
        m = m << 1
    n = n ^ m
    return n

print(subtract_one(5))
print(subtract_one(8))
