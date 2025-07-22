#the bug is in:
if (n & (n - 1)) == 0:
    return True 

#task 2
#This condition correctly identifies powers of two only for positive numbers. But it incorrectly returns True for negative numbers like -2, -8, and -1, because of how negative numbers are represented in binary (two's complement form).

#correct code 
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
