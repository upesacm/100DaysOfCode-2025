def remove_k_digits(num,k):
    stack=[]

    for digit in num:
        while stack and k>0 and stack[-1] > digit:
            stack.pop()
            k -= 1
        stack.append(digit)

    final_stack=stack[:-k] if k else stack

    result = ''.join(final_stack).lstrip('0')

    return result if result else '0'

#example
print(remove_k_digits("1432219",3))