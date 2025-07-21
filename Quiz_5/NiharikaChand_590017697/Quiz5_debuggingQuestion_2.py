"""
1) lines causing the bug are -  if (n & (n - 1)) == 0:
                                    return True

2) It causes incorrect behavior because negative numbers in 2's complement can accidentally satisfy the condition (n & (n-1)) == 0 which may make the function wrongly return True 
"""

# corrected code:
def is_power_of_two(n):
    if n <= 0:      # this condition will check for negative numbers and excludes them 
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

numbers = [0, 1, 2, 3, 4, 8, 16, -2, -8, 1024, 218, -1]
check_numbers(numbers)

