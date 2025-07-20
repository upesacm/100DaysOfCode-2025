# 1. Identify the specific line(s) causing the bug:
# -- if (n & (n - 1)) == 0:
# 2. Why this causes incorrect behavior:
# -- The logic (n & (n - 1)) == 0 works for any number that has only one bit set — which is a defining property of powers of 2.
# --But in two's complement representation, negative numbers can also satisfy this condition due to how bits behave.
# -- So in some cases, especially with small negative values, this condition might misleadingly evaluate to True.
def is_power_of_two(n):
    return n > 0 and (n & (n - 1)) == 0

def check_numbers(arr):
    print("Checking which numbers are powers of two:")
    for num in arr:
        if is_power_of_two(num):
            print(f"{num}: YES")
        else:
            print(f"{num}: NO")
numbers = [0, 1, 2, 8, 16, -2, -8, 1024, ]
check_numbers(numbers)
