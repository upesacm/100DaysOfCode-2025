# 1. Bit Manipulation Bug
def find_unique_pair_buggy(arr):
    """
    This implementation is intended to find two unique numbers in an array
    where all other elements appear exactly twice. However, it contains a bug.
    """
    xor_sum = 0
    for num in arr:
        xor_sum ^= num
    # This correctly isolates the rightmost set bit. This bit is guaranteed
    # to be different between the two unique numbers.
    diff_bit = xor_sum & -xor_sum
    unique1 = 0
    unique2 = 0
    for num in arr:
        # BUG is on the next line:
        # It incorrectly uses `xor_sum` instead of `diff_bit` for grouping.
        if num & xor_sum:
            unique1 ^= num
        else:
            unique2 ^= num
    return unique1, unique2

# Bug 
'''
1. Identify the specific line(s) causing the bug:
The bug is located in the conditional check within the second loop:

if num & xor_sum:


2. Why this causes incorrect behavior:
The goal is to partition the array's numbers into two groups based on a bit
that is different between the two unique numbers. The variable `diff_bit` is
created for this exact purpose; it isolates one such differing bit (specifically,
the rightmost one).

The error is using `xor_sum` as the mask for partitioning. `xor_sum` may have
multiple bits set, and checking `num & xor_sum` will group numbers that share
*any* bit with `xor_sum`, not necessarily the distinguishing `diff_bit`.
This leads to an incorrect grouping, meaning the two unique numbers might end
up in the same group, and the subsequent XOR operations will not isolate them correctly.
'''
### Corrected Code
def find_unique_pair_fixed(arr):
    """
    This is the corrected implementation to find two unique numbers.
    """
    # Step 1: XOR all numbers to get the XOR of the two unique numbers.
    # Duplicates cancel each other out.
    xor_sum = 0
    for num in arr:
        xor_sum ^= num

    # Step 2: Find the rightmost set bit in the xor_sum.
    # This bit is guaranteed to be set in one unique number and not in the other.
    diff_bit = xor_sum & -xor_sum

    # Step 3: Partition the array and find the unique numbers.
    unique1 = 0
    unique2 = 0
    for num in arr:
        # CORRECTION: Group numbers based on whether the `diff_bit` is set.
        # This correctly separates the original array into two groups, with
        # each unique number in a different group.
        if num & diff_bit:
            unique1 ^= num  # XOR numbers in the first group
        else:
            unique2 ^= num  # XOR numbers in the second group
    return unique1, unique2

if __name__ == "__main__":
    Array = [4, 1, 2, 1, 3, 2, 3, 5] 
    # The buggy function might give incorrect results depending on the input.
    # For this specific input, it happens to work, but for others likely it fails.

    bug_result = find_unique_pair_buggy(Array)
    print(f"Buggy function result: {bug_result}")
    fixed_result = find_unique_pair_fixed(Array)
    print(f"Fixed function result: {fixed_result}")