# Implement addition of 1 using only bitwise operations by simulating binary arithmetic carry propagation.
n = int(input("Enter a number: "))
def add_one(n):
    mask = 1
    while n & mask:
        n = n ^ mask
        mask <<= 1
    return n ^ mask

print("Output:", add_one(n))
