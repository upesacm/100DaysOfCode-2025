def is_binary_palindrome(n):
    left = n.bit_length() - 1
    right = 0
    while left > right:
        if ((n >> left) & 1) != ((n >> right) & 1):
            return "No"
        left -= 1
        right += 1
    return "Yes"

print(is_binary_palindrome(9))
print(is_binary_palindrome(10))
