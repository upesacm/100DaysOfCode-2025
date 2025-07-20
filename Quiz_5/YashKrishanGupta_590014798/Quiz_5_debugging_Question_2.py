def is_power_of_two(n):
    if n <= 0: # task 1
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

# task 1 : line no. 2
# task 2 : since code can sometime cause incorrrect behaviour of negative numbers ,hence we should explicitly handle them
