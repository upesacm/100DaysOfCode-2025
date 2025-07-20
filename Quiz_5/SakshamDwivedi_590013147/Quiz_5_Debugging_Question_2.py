def is_power_of_two(n):
    if n <= 0: #It was simply this line, now it checks if the number is less than 0 too, so now it will return false if the number is <= 0.
        #This prevents from negative number from appearing as powers of 2.
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
def is_power_of_two(n):
    if n <= 0: #It was simply this line, now it checks if the number is less than 0 too, so now it will return false if the number is <= 0.
        #This prevents from negative number from appearing as powers of 2.
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
