def toggle_ith_bit(n, i):
    return n ^ (1 << i)

try:
    n = int(input("Enter an integer : ")) 
    i = int(input("Enter the value of i : "))
    print(toggle_ith_bit(n, i))
except:
    print("Invalid input. Please try with a valid input.")
