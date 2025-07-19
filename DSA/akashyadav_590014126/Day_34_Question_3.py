def is_binary_palindrome(x):
    total_bits=x.bit_length()

    for i in range(total_bits // 2):
        left_bit=(x >> i) & 1
        right_bit=(x >> (total_bits - 1 - i)) & 1

        if left_bit != right_bit:
            return False
        return True
    
#example
print(is_binary_palindrome(9))