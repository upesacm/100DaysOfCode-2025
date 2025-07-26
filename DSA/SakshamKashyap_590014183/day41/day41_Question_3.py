def removeKdigits(num: str, k: int) -> str:
    stack = []
    for digit in num:
        while k and stack and stack[-1] > digit:
            stack.pop()
            k -= 1
        stack.append(digit)
    # If k remains, remove from the end
    stack = stack[:-k] if k else stack
    # Strip leading zeros
    result = ''.join(stack).lstrip('0')
    return result if result else "0"

# Test examples
print(removeKdigits("1432219", 3))  # Output: "1219"
print(removeKdigits("10200", 1))    # Output: "200"
