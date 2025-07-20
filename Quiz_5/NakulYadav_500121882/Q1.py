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

# Answer of the given task:
# 1. Identify the specific line(s) causing the bug:
#    The line: if num & xor_sum:
# 2. Why this causes incorrect behavior:
#    It incorrectly uses xor_sum instead of diff_bit to divide the numbers into two groups.
#    xor_sum is the XOR of the two unique numbers and doesn't reliably isolate a differing bit.
#    Using xor_sum causes incorrect grouping and wrong final results.
