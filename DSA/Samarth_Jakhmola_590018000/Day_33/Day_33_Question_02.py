def turn_off_rightmost_set_bit(n):
    return n & (n - 1)

try:
    n = int(input("Enter the an integer : "))
    print(turn_off_rightmost_set_bit(n))
except:
    print("Invalid input. Please try with a valid input.")
