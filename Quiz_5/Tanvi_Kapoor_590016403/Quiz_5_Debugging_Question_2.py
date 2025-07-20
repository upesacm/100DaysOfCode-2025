# ✅ Task 1: Find Two Unique Numbers Using Bit Manipulation
def find_unique_pair(arr):
    xor_sum = 0

    # Step 1: XOR of all elements gives a ^ b (the two unique numbers)
    for num in arr:
        xor_sum ^= num

    # Step 2: Isolate rightmost set bit (bug fix: must use this, not full xor_sum)
    diff_bit = xor_sum & -xor_sum

    unique1 = 0
    unique2 = 0

    # Step 3: Divide numbers into two groups using the distinguishing bit
    for num in arr:
        if num & diff_bit:
            unique1 ^= num
        else:
            unique2 ^= num

    return unique1, unique2


# ✅ Task 2: Check if a number is a power of two
def is_power_of_two(n):
    # Bug fix: Ensure n is positive and not 0
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


# ✅ Main Execution
if __name__ == "__main__":
    print("=== Task 1: Find Two Unique Numbers ===")
    array1 = [2, 4, 7, 9, 2, 4]
    u1, u2 = find_unique_pair(array1)
    print("The two unique numbers are:", u1, "and", u2)

    print("\n=== Task 2: Power of Two Check ===")
    numbers = [0, 1, 2, 3, 4, 8, 16, -2, -8, 1024, 218, -1]
    check_numbers(numbers)
