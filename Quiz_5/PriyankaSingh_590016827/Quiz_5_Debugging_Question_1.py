def find_unique_pair(arr):
    xor_sum = 0
    for num in arr:
        xor_sum ^= num

    # Correctly isolate the rightmost set bit
    diff_bit = xor_sum & -xor_sum

    unique1 = 0
    unique2 = 0
    for num in arr:
        # Use diff_bit instead of xor_sum for correct grouping
        if num & diff_bit:
            unique1 ^= num
        else:
            unique2 ^= num
    return unique1, unique2

arr = list(map(int, input("Enter array elements separated by space: ").split()))
u1, u2 = find_unique_pair(arr)
print("The two unique numbers are:", u1, "and", u2)
