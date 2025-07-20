#bugs :
# Line 5: if (n & (n - 1)) == 0:
# Line 6: return True
# Line 7: return False

#Why this causes incorrect behavior:
# Positive Numbers and Zero: 
# The condition (n & (n - 1)) == 0 is a correct way to check if a positive number is a power of two. However, it also returns true for n = 0. The problem explicitly states "numbers that are powers of two".
# While the initial if n == 0: return False correctly handles zero, the problem lies with negative numbers.

# Negative Numbers:
# The is_power_of_two function does not correctly handle negative numbers.
# For example, if n = -2, n - 1 = -3.
# In two's complement representation (assuming 32-bit):
# -2 is ...1111 1110
# -3 is ...1111 1101
# (-2) & (-3) results in ...1111 1100, which is -4 (not 0). So, it would incorrectly return False.
# The core definition of a power of two usually refers to positive integers (2^0 ,2^1 ,2^2 ,ldots). 
# Bitwise operations like n & (n - 1) are typically applied to unsigned or positive integers because the behavior with negative numbers 
# (due to two's complement representation) is not intuitive for this specific check and won't yield the desired result for "power of two."
#correct code 
def is_power_of_two(n):
  
    return n > 0 and (n & (n - 1)) == 0

def check_numbers(arr):
    print("Checking which numbers are powers of two:")
    for num in arr:
        if is_power_of_two(num):
            print(f"{num}: YES")
        else:
            print(f"{num}: NO")


numbers = [0, 1, 2, 3, 4, 8, 16, -2, -8, 1024, 218, -1]
check_numbers(numbers)
