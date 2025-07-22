def subtract_one(n):
    borrow = 1
    mask = 1
    while borrow:
        if n & mask:
            n = n ^ mask
            borrow = 0
        else:
            n = n | mask
            mask <<= 1
    return n 

try:
    n = int(input("Enter an integer : "))
    print(subtract_one(n))
except:
    print("Invalid input. Please try with a valid input.")
