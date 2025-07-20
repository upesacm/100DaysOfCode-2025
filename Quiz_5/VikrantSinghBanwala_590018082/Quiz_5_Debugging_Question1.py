#1.the linw which have bug is 
#  if num & xor_sum:
#2.The bug occurs because the condition if num & xor_sum incorrectly groups numbers based on overall XOR value
#  instead of rightmost set bit. This leads to incorrect separation of two unique numbers, resulting
#  in incorrect outputs. The condition should use diff_bit instead to properly differentiate the unique numbers.

# correct code
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
