#Solution 1 for Quiz 5 Debugging Question 1

def find_unique_pair(arr):
    xor_sum = 0
    for num in arr:
        xor_sum ^= num  # XOR of all elements: leaves us with unique1 ^ unique2

    # Isolate the rightmost bit where the two unique numbers differ
    diff_bit = xor_sum & -xor_sum  # Correct: isolates one set bit from the xor_sum

    unique1 = 0
    unique2 = 0
    for num in arr:
        #  Task 1: BUGGY LINE — incorrect bit check condition
        if num & xor_sum:  #  BUG: This compares against full xor_sum (many bits)
            unique1 ^= num
        else:
            unique2 ^= num

    return unique1, unique2


# Task 2: Explanation of the Bug
# The condition `num & xor_sum` wrongly uses all bits in xor_sum.
# Since xor_sum = unique1 ^ unique2, it may have multiple bits set.
# This can misplace numbers into wrong groups, especially the duplicates, ruining the XOR grouping logic.

# FIX: Use a **single bit** that is different between unique1 and unique2.
# We extract this bit using `diff_bit = xor_sum & -xor_sum`.
# It ensures that:
# - All duplicates fall into the correct group (either 0 or 1 at that bit),
# - And the two unique numbers fall into **different** groups, so XOR isolates them correctly.
