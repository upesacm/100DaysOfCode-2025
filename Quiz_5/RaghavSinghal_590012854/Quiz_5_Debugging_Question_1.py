# 1. Bit Manipulation Bug

# The following implementation is intended to find two unique numbers in an array where 
# all other elements appear exactly twice. However, it contains a bug. Identify the error 
# and explain why it causes incorrect behavior:

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
        if num & diff_bit:
            unique1 ^= num
        else:
            unique2 ^= num
    return unique1, unique2
print(find_unique_pair([1,1,2,2,3,3,4,5]))
# Tasks: 

# 1. Identify the specific line(s) causing the bug
# The if condition, it should be diff_bit

# 2. Why this causes incorrect behavior:
# Because diff bait has the lsb with we will se to find the 2 unique numbers
