def is_power_of_two(n):
    if n <= 0:
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
