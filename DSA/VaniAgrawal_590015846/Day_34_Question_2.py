#  Implement subtraction of 1 using only bitwise operations by simulating binary arithmetic borrow propagation.
n = int(input("Enter a number: "))
def subtract_one(n):
    mask = 1
    while not (n & mask):
        n = n ^ mask
        mask <<= 1
    return n ^ mask

print("Output:", subtract_one(n))
