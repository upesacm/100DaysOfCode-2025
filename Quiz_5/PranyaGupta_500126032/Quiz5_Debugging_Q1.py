#1. Line 14 is causing error, it should be num & diff_bit
#2.The bug is in using num & xor_sum for grouping, which checks more than 1 bits and may give wrong output. Using num & diff_bit checks just one differing bit, ensuring correct grouping and result.
def find_unique_pair(arr):
    xor_sum = 0
    for num in arr:
        xor_sum ^= num

    # This isolates the rightmost set bit
    diff_bit = xor_sum & -xor_sum

    unique1 = 0
    unique2 = 0
    for num in arr:
        # This condition incorrectly groups numbers
        if num & xor_sum:
            unique1 ^= num
        else:
            unique2 ^= num
    return unique1, unique2