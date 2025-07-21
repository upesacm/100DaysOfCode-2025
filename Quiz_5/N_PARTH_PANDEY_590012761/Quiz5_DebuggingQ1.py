#1. Identify the specific line(s) causing the bug
if num & xor_sum:  # Incorrect condition
    unique1 ^= num
else:
    unique2 ^= num
#The condition num & xor_sum is incorrect. It should instead use num & diff_bit to properly separate the two unique numbers based on their differing bit.

#2. Why this causes incorrect behavior ?
# The condition `num & xor_sum` incorrectly groups numbers by checking *any* shared bit with `xor_sum`, causing duplicates to leak and unique numbers to merge. The fix (`num & diff_bit`) isolates the *rightmost differing bit* to properly split the array, ensuring duplicates cancel out and uniques separate correctly.  

