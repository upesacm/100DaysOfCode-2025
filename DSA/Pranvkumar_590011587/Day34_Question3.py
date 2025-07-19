# 3. Check if Binary Representation is a Palindrome
def is_binary_palindrome(n):
    num_bits = n.bit_length()
    for i in range(num_bits // 2):
        left_bit = (n >> (num_bits - 1 - i)) & 1
        right_bit = (n >> i) & 1
        if left_bit != right_bit:
            return "No"
    return "Yes"

# --- Test Cases ---
if __name__ == "__main__":
    # Binary Palindrome Check
    print("\nBinary Palindrome Check:")
    print("Input: 9 -> Output:", is_binary_palindrome(9))    
    print("Input: 10 -> Output:", is_binary_palindrome(10))