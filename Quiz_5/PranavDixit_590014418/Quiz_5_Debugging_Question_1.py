"""
Bit Manipulation Debugging Report
---------------------------------

🔧 Task 1: Identify the Bug
---------------------------
❌ Buggy Line:
    if num & xor_sum:

✅ Corrected Line:
    if num & diff_bit:

Explanation:
We need to isolate a single differing bit between the two unique numbers using:
    diff_bit = xor_sum & -xor_sum
This gives the rightmost set bit (which is guaranteed to differ between the two unique values).
Using `xor_sum` directly in the condition checks *all* differing bits, which may incorrectly group
elements — causing incorrect results when XOR-ing.

🔍 Task 2: Why This Causes Incorrect Behavior
--------------------------------------------
- `xor_sum` is the XOR of the two unique elements — it highlights *all* the differing bits.
- To separate the two unique numbers into distinct groups, we must use *only one bit* where they differ.
- This is done correctly using: `diff_bit = xor_sum & -xor_sum`
- If we instead use `num & xor_sum`, it will check multiple bits, potentially grouping duplicates incorrectly.
- As a result, the XOR cancellation fails, and the final answer is wrong.
"""

def find_unique_pair(arr):
    xor_sum = 0
    for num in arr:
        xor_sum ^= num

    # ✅ Correctly isolate the rightmost set bit
    diff_bit = xor_sum & -xor_sum

    unique1 = 0
    unique2 = 0
    for num in arr:
        # ✅ Use diff_bit to split the array properly
        if num & diff_bit:
            unique1 ^= num
        else:
            unique2 ^= num

    return unique1, unique2

# Example test case
arr = [1, 2, 3, 2, 1, 4]
print(find_unique_pair(arr))  # Output: (3, 4) or (4, 3)
