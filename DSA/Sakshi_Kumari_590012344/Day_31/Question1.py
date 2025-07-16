def is_power_of_two(n):
    if n <= 0:
        return False
    if (n & (n - 1)) == 0:
        return True
    else:
        return False

num = int(input("Enter a number: "))
if is_power_of_two(num):
    print(num, "is a power of 2.")
else:
    print(num, "is not a power of 2.")
