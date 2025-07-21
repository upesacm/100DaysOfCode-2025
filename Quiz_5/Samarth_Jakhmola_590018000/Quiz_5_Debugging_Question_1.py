'''

1. The bug is in the line "if num & xor_sum:".

2. We should group the numbers based on whether the bit next to 'diff_bit' is 1 or 0 and not on xor_sum because xor_sum is the xor of 2
   unique numbers and it may have more than 1 bits set. We isolate just one bit that is guaranteed to distinguish between the 2 numbers in
   'diff_bit'.
    So, the correct line should be " if num & diff_bit: ".

'''
