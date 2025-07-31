def remove_k_digits(num, k):
    stack = []
    for digit in num:
        while stack and k > 0 and stack[-1] > digit:
            stack.pop()
            k -= 1
        stack.append(digit)
    while k > 0:
        stack.pop()
        k -= 1
    result = ''.join(stack).lstrip('0')
    return result if result else '0'

# Examples
print(remove_k_digits("1432219", 3))   # Output: "1219"
print(remove_k_digits("10200", 1))     # Output: "200"
print(remove_k_digits("10", 2))        # Output: "0"
print(remove_k_digits("1234567890", 9))# Output: "0"
print(remove_k_digits("10001", 1))     # Output: "0"
