#Solution 2 for Quiz 5 Debugging Question 2

def is_power_of_two(n):
    # Task 1: BUG — missing check for negative numbers and zero
    if n == 0:
        return False

    # This works for positive powers of two,
    # but may return True for some negatives due to Python’s handling of binary on negatives
    if (n & (n - 1)) == 0:
        return True
    return False


# Task 2: Explanation of the Bug
# The function doesn’t account for negative numbers or zero.
# In binary, negative integers in Python are represented using **infinite two’s complement**, which can trick bitwise logic.
# For example: `-8 & -9 == 0` gives a **false positive**, but -8 is **not** a power of two.

# FIX: Add a condition to ensure the number is **strictly positive** before the bitwise test.
# Correct version:
# def is_power_of_two(n):
#     if n <= 0:
#         return False
#     return (n & (n - 1)) == 0
