def add_one(n):
    m = 1
    while n & m:
        n = n ^ m
        m = m << 1
    n = n ^ m
    return n

print(add_one(4))
print(add_one(7))
