def find_unique_pair(arr):
    xor_sum = 0
    for num in arr:
        xor_sum ^= num

    # This isolates the rightmost set bit
    diff_bit = xor_sum & -xor_sum

    unique1 = 0
    unique2 = 0
    for num in arr:
        # This condition incorrectly groups numbers
        if num & diff_bit:  #task 1
            unique1 ^= num
        else:
            unique2 ^= num
    return unique1, unique2

#task 1 : line no. 13
#task 2 : num & xor_sum will cause incoorect behaviour if the xor_sum has more than one set bit , it will mix the numbers
