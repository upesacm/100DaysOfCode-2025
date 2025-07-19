def add_one(n):
    carry = 1
    while carry:
        sum = n ^ carry   # XOR adds the bits
        carry = (n & carry) << 1   # AND finds the carry and shifts it to the left
        n = sum
    return n

try:
    n = int(input("Enter an integer : "))
    print(add_one(n))
except:
    print("Invalid input. Please try with a valid input.")
