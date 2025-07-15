def ith_bit(n, i):
    mask = 1 << i   # Creating a mask (element of the same length as the integer when represented in binary) with just the ith bit one
    return 1 if (n & mask) != 0 else 0 

try:
    n = int(input("Enter an integer : "))
    i = int(input("Enter the position of the bit, i.e., i : "))
    print(ith_bit(n, i))
except:
    print("Invalid input. Please try with a valid input.")
