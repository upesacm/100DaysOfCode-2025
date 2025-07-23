1.
if (n & (n - 1)) == 0:
This line is not safe for negative numbers.

Also, the function does not check if n is positive, which is crucial.

2.
Negative numbers in Python use two's complement binary representation, and the bitwise expression (n & (n - 1)) == 0 gives incorrect results for them.
For example:
n = -2 in binary is not clean like 0000...0010, so the check (n & (n - 1)) doesn’t behave as expected.

Negative numbers cannot be powers of two, yet the function might falsely say "YES".


Suggested fix:
def is_power_of_two(n):
    if n <= 0:
        return False
    return (n & (n - 1)) == 0


def check_numbers(arr):
    print("Checking which numbers are powers of two:")
    for num in arr:
        if is_power_of_two(num):
            print(f"{num}: YES")
        else:
            print(f"{num}: NO")

numbers = [0, 1, 2, 3, 4, 8, 16, -2, -8, 1024, 218, -1]
check_numbers(numbers)

