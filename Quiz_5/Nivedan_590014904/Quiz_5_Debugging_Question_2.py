def is_power_of_two(n):
    if n <= 0:   #THe bug was here 
        return False

    if (n & (n - 1)) == 0: #THis logic doesnt work with negative numbers hence sometimes it was giving this truye while the power of 2 cant be negative.
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
