def remove_k_digits(num: str, k: int) -> str:
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
    return result if result else "0"

# Example Usage
print(remove_k_digits("1432219", 3)) 
print(remove_k_digits("10200", 1))  