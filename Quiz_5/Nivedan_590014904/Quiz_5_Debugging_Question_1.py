def find_unique_pair(arr):
    xor_sum = 0
    for num in arr:
        xor_sum ^= num

    # This isolates the rightmost set bit
    diff_bit = xor_sum & -xor_sum

    unique1 = 0
    unique2 = 0
    for num in arr:
        # This condition correctly groups numbers
        """before we're using the AND operation with xor sum which doesnt do anything instead we had to use the diff_bit to XOR with"""
        if num & diff_bit: #it was this line 
            unique1 ^= num
        else:
            unique2 ^= num
    return unique1, unique2
