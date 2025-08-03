#The bug is in the line:
#if num & xor_sum:

#The xor_sum at that point holds the XOR of the two unique numbers. For example, if the two unique numbers are 3 (011) and 5 (101), their xor_sum would be 6 (110). If we then check if num & xor_sum, numbers like 2 (010) would satisfy the condition because the 1st bit is set in both 2 and 6. This would lead to incorrect grouping.

# Correct Approach:
# After calculating xor_sum (which is U_1oplusU_2), we need to find a rightmost set bit (or any set bit) in xor_sum. This diff_bit guarantees that one of the unique numbers has this bit set and the other doesn't.
# The line diff_bit = xor_sum & -xor_sum correctly isolates the rightmost set bit.

# The partitioning should then be based on whether diff_bit is set in num or not. The correct condition should be:
# if num & diff_bit:

# This ensures that numbers are grouped based on the specific bit that differentiates the two unique numbers.

# correct code 
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
            
    return unique1, unique2
