# Swap two numbers using XOR without a temporary variable
# Taking input from the user
a = int(input("Enter the first number (a): "))
b = int(input("Enter the second number (b): "))
print(f"\nBefore swapping: a = {a}, b = {b}")
# XOR swapping
a = a ^ b
b = a ^ b  
a = a ^ b  
print(f"After swapping: a = {a}, b = {b}")
#for example:
# Input: a = 5, b = 10
# Output: a = 10, b = 5