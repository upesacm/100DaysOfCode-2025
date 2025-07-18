def find_xor_of_array(numbers):
    xor_result = 0
    for number in numbers:
        xor_result ^= number
    return xor_result
