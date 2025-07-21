def find_unique_pair(arr):
    xor_sum = 0

    # Step 1: XOR all elements
    for num in arr:
        xor_sum ^= num

    # Step 2: Isolate the rightmost set bit (this bit differs in the two unique numbers)
    diff_bit = xor_sum & -xor_sum

    unique1 = 0
    unique2 = 0

    # Step 3: Divide numbers into two groups based on the isolated bit
    for num in arr:
        if num & diff_bit:
            unique1 ^= num
        else:
            unique2 ^= num

    return unique1, unique2


# ✅ Example usage:
arr = [2, 4, 7, 9, 2, 4]
u1, u2 = find_unique_pair(arr)
print("The two unique numbers are:", u1, "and", u2)
