def swap(a, b):
    a = a ^ b
    b = a ^ b
    a = a ^ b
    print(f"a = {a}, b = {b}")

try:
    a, b = map(int, input("Enter the values of integers a and b separated by spaces : ").split())
    swap(a, b)
except:
    print("Invalid input. Please try with a valid input.")
