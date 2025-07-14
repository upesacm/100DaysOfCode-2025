def set_ith_bit(n, i):
    mask = 1 << i
    return n | mask

try:
    n = int(input("Enter an integer : "))
    i = int(input("Enter the value of i : "))
    print(set_ith_bit(n, i))
except:
    print("Invalid input. Please try with a valid input.")
