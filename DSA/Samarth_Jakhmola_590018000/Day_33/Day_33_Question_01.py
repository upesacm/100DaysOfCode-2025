def check_opposite_signs(a, b):
    return (a ^ b) < 0

try:
    a, b = map(int, input("Enter the values of integers a and b separated by spaces : ").split())
    print(check_opposite_signs(a, b))
except:
    print("Invalid input. Please try with a valid input.")
