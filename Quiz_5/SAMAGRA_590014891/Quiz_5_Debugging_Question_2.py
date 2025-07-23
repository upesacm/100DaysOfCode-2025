def is_power_of_two(n):
    # Task 1: Bug was here — the original bitwise check didn't rule out negative numbers or zero
    if n <= 0:
        # Task 2: Why this caused incorrect behavior —
        # Negative numbers like -2 or -8 passed the (n & (n - 1)) == 0 check,
        # but powers of two must be positive integers. This fixes that.
        return False

    # Now safe to apply the bitwise trick only to positive numbers
    return (n & (n - 1)) == 0


def check_numbers(arr):
    print("Checking which numbers are powers of two:")
    for num in arr:
        if is_power_of_two(num):
            print(f"{num}: YES")
        else:
            print(f"{num}: NO")

#test case
numbers = [0, 1, 2, 3, 4, 8, 16, -2, -8, 1024, 218, -1]
check_numbers(numbers)
