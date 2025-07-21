def find_unique_pair(arr):
    xor_sum = 0
    for num in arr:
        xor_sum ^= num

    diff_bit = xor_sum & -xor_sum

    unique1 = 0
    unique2 = 0
    for num in arr:
        if num & diff_bit:
            unique1 ^= num
        else:
            unique2 ^= num

    return unique1, unique2

arr = [2, 3, 7, 9, 2, 3]
result = find_unique_pair(arr)
print(f"Two unique numbers are: {result}")
