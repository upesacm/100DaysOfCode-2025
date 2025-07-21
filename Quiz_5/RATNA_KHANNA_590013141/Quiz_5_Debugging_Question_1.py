#1. bug- line 13: if num & xor_sum:
#correct- if num & diff_bit:
#2. By using xor_sum instead of diff_bit, we end up grouping both unique numbers into the same group,especially if both a and b share some bits in common with xor_sum
#correct code--
def find_unique_pair(arr):
    xor_sum = 0
    for num in arr:
        xor_sum ^= num

    # Isolate rightmost set bit where the two numbers differ
    diff_bit = xor_sum & -xor_sum

    unique1 = 0
    unique2 = 0
    for num in arr:
        if num & diff_bit:  # ✅ Correct condition
            unique1 ^= num
        else:
            unique2 ^= num
    return unique1, unique2
