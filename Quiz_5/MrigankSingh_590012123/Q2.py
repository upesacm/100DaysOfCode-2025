def is_power_of_two(n):
    if n == 0:
        return False

    # Task 1: BUGGY LINE — lacks check for negative numbers
    if (n & (n - 1)) == 0:
        return True
    return False

# Task 2: Explanation
# This condition fails for negative numbers (like -8), because bitwise operations on negatives
# can misleadingly return `True` for the power-of-two test. But negative numbers are not considered powers of two.
# The fix is to ensure `n > 0` before checking `n & (n-1) == 0`.

# Correct version should be:
# def is_power_of_two(n):
#     if n <= 0:
#         return False
#     return (n & (n - 1)) == 0


def check_numbers(arr):
    print("Checking which numbers are powers of two:")
    for num in arr:
        if is_power_of_two(num):
            print(f"{num}: YES")
        else:
            print(f"{num}: NO")

numbers = [0, 1, 2, 3, 4, 8, 16, -2, -8, 1024, 218, -1]
check_numbers(numbers)
