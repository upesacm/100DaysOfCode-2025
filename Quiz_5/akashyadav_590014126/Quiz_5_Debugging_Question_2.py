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

#Task 
#if (n & (n - 1)) == 0, This condition works for positive powers of two, but does not handle negative numbers, which aren't valid powers of two
#reason:Bitwise operations on negative integers follows two's complement logic, which can make (n & (n - 1)) == 0 appear true for some negative values like -2 or -8, even though they're not powers of two.
