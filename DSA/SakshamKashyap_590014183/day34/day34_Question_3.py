def is_binary_palindrome(n):
    num_bits = n.bit_length()
    for i in range(num_bits // 2):
        left_bit = (n >> (num_bits - i - 1)) & 1
        right_bit = (n >> i) & 1
        if left_bit != right_bit:
            return "No"
    return "Yes"

print(is_binary_palindrome(9))  
print(is_binary_palindrome(10))  
