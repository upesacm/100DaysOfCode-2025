#ques1
##if n == 0: return False
#if (n & (n - 1)) == 0: return True
#ques 2
#Bitwise operations on negative numbers in Python can give unexpected results due to infinite two's complement representation.
##1 as Edge Case: Mathematically, 1 is 2^0, so if the definition includes 1 as a power of two, then it's correct.
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

# Sample test
numbers = [0, 1, 2, 3, 4, 8, 16, -2, -8, 1024, 218, -1]
check_numbers(numbers)


