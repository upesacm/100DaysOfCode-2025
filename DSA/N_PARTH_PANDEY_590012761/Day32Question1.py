a = int(input("Enter the 1st number: "))
b = int(input("Enter the 2nd number: "))
a ^= b
b ^= a
a ^= b
print(f"a = {a}, b = {b}")

