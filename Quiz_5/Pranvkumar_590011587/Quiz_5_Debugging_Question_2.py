# 2. Check Power of Two Bug

def is_power_of_two(n):
    # This check for 0 is necessary because (0 & -1) is 0.
    if n == 0:
        return False
    # This bitwise trick works for positive powers of two.
    if (n & (n - 1)) == 0:
        return True
    return False

def check_numbers_buggy(arr):
    print("Checking which numbers are powers of two (Buggy Version):")
    for num in arr:
        # The bug is in the is_power_of_two function, which does not
        # correctly handle all cases as per the mathematical definition.
        if is_power_of_two(num):
            print(f"{num}: YES")
        else:
            print(f"{num}: NO")


# Bug 
''''
1. Identify the specific line(s) causing the bug:
The bug is conceptual and lies in the implementation of `is_power_of_two(n)`.
The function fails to account for the standard definition of a power of two,
which requires the number to be positive.

if (n & (n - 1)) == 0:

2. Why this causes incorrect behavior:
A number is a power of two if it can be expressed as $2^k$ where k is a non-negative
integer ($k \ge 0$). This means the number must be positive (e.g., 1, 2, 4, 8...).
The bitwise trick `(n & (n - 1)) == 0` is a clever way to check this property, but
it's only meaningful for positive integers. The buggy function does not explicitly
check if `n > 0`. While it happens to return `False` for negative numbers (due to
how two's complement works) and has a special case for `0`, it is not a robust
or clear implementation. A correct function must first ensure the number is positive.
'''

### Correct Code

def is_power_of_two_fixed(n):
    """
    Checks if a number is a power of two ($2^k$ for k >= 0).
    A robust and concise implementation.
    """
    # CORRECTION: A power of two must be positive.
    # This single expression correctly handles all cases:
    # 1. n > 0: Ensures n is positive.
    # 2. (n & (n - 1)) == 0: The bitwise trick to check for the power of two property.
    return n > 0 and (n & (n - 1)) == 0

def check_numbers_fixed(arr):
    """
    Uses the fixed function to check for powers of two.
    """
    print("\nChecking which numbers are powers of two (Fixed Version):")
    for num in arr:
        if is_power_of_two_fixed(num):
            print(f"{num}: YES")
        else:
            print(f"{num}: NO")

if __name__ == "__main__":
    # Demo 
    numbers_to_check = [0, 1, 2, 3, 4, 8, 16, -2, -8, 1024, 218, -1]
    check_numbers_buggy(numbers_to_check)
    check_numbers_fixed(numbers_to_check)