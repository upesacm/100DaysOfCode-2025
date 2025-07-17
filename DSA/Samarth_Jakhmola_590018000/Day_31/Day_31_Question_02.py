def multiply_by_2(n):
    return n << 1  # Multiplying a number by 2 is equivalent to shifting its binary representation left by one bit.

try:
    n = int(input("Enter an integer : "))
    print(multiply_by_2(n))
except:
    print("Invalid input. Please try with a valid input.")
