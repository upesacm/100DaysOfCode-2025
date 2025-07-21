"""
Debugging Report – Bit Manipulation Problem
-------------------------------------------

Task 1: Identify the Bug
------------------------
The main issue is in this line:

    if num & xor_sum:

This line is supposed to split the numbers into two groups based on a differing bit between the two unique elements.
But using `xor_sum` here is incorrect because it checks multiple bits instead of just one.

What we should be using instead is:

    if num & diff_bit:

This `diff_bit` is calculated using `xor_sum & -xor_sum` and gives us the rightmost set bit.
That single bit is enough to differentiate the two unique numbers and separate the rest correctly.

Task 2: Why This Causes Incorrect Behavior
------------------------------------------
Here's why using `xor_sum` directly breaks the logic:

- `xor_sum` is the XOR of the two unique numbers. It gives us a result where the bits that differ between the two numbers are set.
- But if we try to split the numbers based on `xor_sum`, we might be checking multiple bits at once, which causes numbers that should cancel out to end up in the wrong group.
- Instead, using just one specific bit (`diff_bit`) makes sure we divide all numbers into two correct groups where duplicates cancel each other, and the two unique numbers remain in the end.

Hope that makes sense!
"""

def find_unique_pair(arr):
    xor_sum = 0
    for num in arr:
        xor_sum ^= num

    # Fix: use the rightmost set bit to distinguish the two unique numbers
    diff_bit = xor_sum & -xor_sum

    unique1 = 0
    unique2 = 0
    for num in arr:
        # Correct grouping using diff_bit
        if num & diff_bit:
            unique1 ^= num
        else:
            unique2 ^= num

    return unique1, unique2


# Example test case
arr = [1, 2, 3, 2, 1, 4]
print(find_unique_pair(arr))  # Output: (3, 4) or (4, 3)
