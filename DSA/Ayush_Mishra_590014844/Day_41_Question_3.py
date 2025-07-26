def remove_k_digits(num, k):
    stack = []
    for digit in num:
        while k and stack and stack[-1] > digit:
            stack.pop()
            k -= 1
        stack.append(digit)
    stack = stack[:-k] if k else stack
    result = ''.join(stack).lstrip('0')
    return result if result else "0"

num = input("Enter the number: ")
k = int(input("Enter k: "))
print(remove_k_digits(num, k))
