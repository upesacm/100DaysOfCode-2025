def isolate_rightmost_bit(n):
    return n & -n  

try:
    n = int(input("Enter the an integer : "))
    print(isolate_rightmost_bit(n))
except:
    print("Invalid input. Please try with a valid input.")
