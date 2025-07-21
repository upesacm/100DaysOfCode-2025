def find_unique_pair(arr):
    xor_sum = 0
    for num in arr:
        xor_sum ^= num  

    # Isolate the rightmost set bit that differs between the two unique numbers
    diff_bit = xor_sum & -xor_sum

    unique1 = 0
    unique2 = 0
    for num in arr:
        # Bug: Originally used 'if num & xor_sum', which is incorrect because xor_sum may have multiple set bits
        # Fix: Use 'diff_bit' to correctly group numbers based on the differing bit
        if num & diff_bit:
            unique1 ^= num
        else:
            unique2 ^= num

    return unique1, unique2

# Test run
arr = [2, 3, 7, 9, 2, 3, 11, 9]  # 7 and 11 are the only unique numbers
print("The two unique numbers are:", find_unique_pair(arr))
