#1.bug- if (n & (n - 1)) == 0:
#2.The function incorrectly identifies negative numbers and zero as powers of two.
def is_power_of_two(n):
    # Return False if n is not positive
    if n <= 0:
        return False
    # True only if n has exactly one set bit
    return (n & (n - 1)) == 0

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
