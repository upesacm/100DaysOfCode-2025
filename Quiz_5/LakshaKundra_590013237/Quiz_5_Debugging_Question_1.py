# if num & xor_sum: this line has error
# the correct line should be if num & diff_bit:

#task2
#The purpose of this condition is to partition the array into two groups based on a bit where the two unique numbers differ.
#This is done using:
#diff_bit = xor_sum & -xor_sum
#Which correctly isolates the rightmost set bit in xor_sum.
#if num & xor_sum:
#incorrectly checks against the entire XOR sum, not the isolated bit.
#As a result, Some numbers may go into the wrong group.

#correct code 
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
