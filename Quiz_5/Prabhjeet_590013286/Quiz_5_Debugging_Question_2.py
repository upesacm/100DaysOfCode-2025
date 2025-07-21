def is_power_of_two(n):
    if n == 0:
        return False
    
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
# Answers of given task :
# 1. Identify the specific line(s) causing the bug:
#    The bug is in: if (n & (n - 1)) == 0:
# 2. Why this causes incorrect behavior:
#    This condition works correctly only for positive powers of two.
#    Negative numbers like -2 and -8 also satisfy the condition because of how negative binary numbers are represented (two's complement).
#    As a result, negative numbers can incorrectly be identified as powers of two.
#    The function should include an additional check to ensure n is positive: if n > 0 and (n & (n - 1)) == 0
