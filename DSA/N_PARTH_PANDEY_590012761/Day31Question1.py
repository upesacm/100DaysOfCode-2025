def is_power_of_two(n):
    return n != 0 and (n & (n - 1)) == 0

n = int(input("Enter a number: "))
if is_power_of_two(n):
    print("Yes")
else:
    print("No")