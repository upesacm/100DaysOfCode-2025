1. Identify the specific line(s) causing the bug
if num & xor_sum:  

2. Why this causes incorrect behavior:
xor_sum contains the XOR of the two unique numbers, say x ^ y.

It highlights all differing bits between the two, not just one.

Using num & xor_sum may group both unique numbers into the same group, which breaks the logic.

