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
        if num & diff_bit: '''This should be diff_bit and not xor_sum, as num & xor_sum checks if a number has any of the same bits
        the xor'ed elements. Because of this the grouping occurs randomly instead of the duplicates grouping in separate groups.
        In num & diff_bit the two duplicates are grouped in different groups and cancel each other out.'''
            unique1 ^= num
        else:
            unique2 ^= num
    return unique1, unique2

print(find_unique_pair([3, 3, 4, 4, 1, 2]))
