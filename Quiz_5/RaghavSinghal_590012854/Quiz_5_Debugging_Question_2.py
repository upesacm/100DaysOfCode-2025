# 2. Check Power of Two Bug

# The following function is intended to check whether numbers in a given list are powers of two. It prints "YES" for numbers that are powers of two and "NO" otherwise. However, the function has bugs that cause incorrect outputs for some inputs

def is_power_of_two(n):
    if n == 0:
        return False
    if(n<0): n=-n;

    if (n & (n - 1)) == 0:
        return True
    return False


def check_numbers(arr):
    print("Checking which numbers are powers of two:")
    for num in arr:
        if is_power_of_two(num):
            print(f"{num}: YES")
        else:
            print(f"{num}: NO")

# Sample test
numbers = [0, 1, 2, 3, 4, 8, 16, -2, -8, 1024, 218, -1]
check_numbers(numbers)

# Tasks: 

# 1. Identify the specific line(s) causing the bug:
# line 9 as it does not work for negative numbers

# 2. Why this causes incorrect behavior:
# thta logic doesnot work with negative numbers beacuse of signed bit