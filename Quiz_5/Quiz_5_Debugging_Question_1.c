
Tasks: 

1. Identify the specific line(s) causing the bug

2. Why this causes incorrect behavior:

task1
def find_unique_pair(arr):
    xor_sum = 0
    for num in arr:
        xor_sum ^= num

    diff_bit = xor_sum & -xor_sum

    unique1 = 0
    unique2 = 0
    for num in arr:
        if num & diff_bit:  # ✅ Correct grouping
            unique1 ^= num
        else:
            unique2 ^= num
    return unique1, unique2
task2
The mistake is in this line:
if num & xor_sum:
Correct condition should be- if num & diff_bit:
