def divide_by_2(n):
    return int(n) >> 1    # Dividing a numbe by 2 is equivalent to shifting its binary representation right by one.

try:
    n = float(input("Enter a number : "))
    print(divide_by_2(n))
except:
    print("Invalid input. Please try with a valid input.")
