def find_unique_pair(arr):
    xor_sum = 0
    for num in arr:
        xor_sum ^= num  # XOR of all elements: xor_sum = unique1 ^ unique2

    # This isolates the rightmost set bit (correct)
    diff_bit = xor_sum & -xor_sum

    unique1 = 0
    unique2 = 0
    for num in arr:
        # Task 1: BUGGY LINE — incorrect condition used
        if num & xor_sum:  # BUG: Should be `num & diff_bit`
            unique1 ^= num
        else:
            unique2 ^= num

    return unique1, unique2

# Task 2: Explanation
# This condition uses `num & xor_sum`, which may check *multiple bits* instead of a single differing bit.
# As a result, it can incorrectly split the duplicate numbers into the wrong groups, breaking the XOR logic.
# Using `diff_bit` ensures all duplicate numbers fall into the same group and only the unique numbers get isolated correctly.
