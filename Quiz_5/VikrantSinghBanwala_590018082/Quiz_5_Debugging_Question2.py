#1.line which give error is 
#  if n == 0:
#  return False

#2.The bug occurs because function does not handle negative numbers. While it correctly returns False for 0,
# it fails to explicitly check for negative values, which cannot be powers of two. This leads to incorrect outputs
# for negative inputs, as they should return "NO". The function should check if $ n $ is positive before evaluating
# it as a power of two.

#corrected code
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
