#1. Identify the specific line(s) causing the bug
# -- if num & xor_sum: 
#    correct shoud be -- if num & diff_bit:
#2. Why this causes incorrect behavior:
# -- This isolates the rightmost set bit in the XOR of the two unique numbers. It guarantees that the two unique numbers differ at that bit.
# But in the faulty implementation, the grouping uses xor_sum, which has multiple bits set — so some numbers may be incorrectly grouped together even if they don’t differ in the isolated bit. This can lead to:
#   - Mixing both unique numbers in one group
#   - Cancelling them out with other duplicates
#   -Incorrect final results
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

    return unique1, unique2
