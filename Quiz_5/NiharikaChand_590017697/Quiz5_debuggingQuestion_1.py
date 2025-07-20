"""
1) bug is in the line if num & xor_sum:
2) It causes incorrect behavior because num & xor_sum tries to split numbers using all set bits in xor_sum not just one which can put both unique numbers in the same group
"""

#corrected code
def find_unique_pair(arr):
    xor_sum = 0
    for num in arr:
        xor_sum ^= num

    diff_bit = xor_sum & -xor_sum  

    unique1 = 0
    unique2 = 0
    for num in arr:
        if num & diff_bit:  # using diff_bit instead of not xor_sum
            unique1 ^= num
        else:
            unique2 ^= num
    return unique1, unique2
