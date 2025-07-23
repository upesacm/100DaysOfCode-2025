1. if num & xor_sum: This line is incorrect.

It should be:
if num & diff_bit: 

2.
The bug happens because `xor_sum = x ^ y` has multiple set bits—each one where `x` and `y` differ. To separate `x` and `y`, 
we isolate just **one** set bit using `diff_bit = xor_sum & -xor_sum`.
But the code incorrectly uses `num & xor_sum` to split the array, which checks **all** differing bits. This can group both unique numbers together, 
leading to wrong results.
It should use `num & diff_bit` to correctly separate `x` and `y`.

CORRECTED CODE:
def find_unique_pair(arr):
    xor_sum = 0
    for num in arr:
        xor_sum ^= num

    # Correct: isolate rightmost differing bit
    diff_bit = xor_sum & -xor_sum

    unique1 = 0
    unique2 = 0
    for num in arr:
        # Correct: group by isolated bit
        if num & diff_bit:
            unique1 ^= num
        else:
            unique2 ^= num

    return unique1, unique2
