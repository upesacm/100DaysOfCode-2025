stack = []

def push(stack, num):
    stack.append(num)

def pop(stack):
    return stack.pop()

def peek(stack):
    if stack:
        return stack[-1]
    else:
        return "Stack is empty!"

'''
These are not required but are basic stack functions.
def display():
    if stack:
        print(stack)
    else:
        print("Stack is empty!")
'''

def remove_k_digits(num, k):
    global stack
    stack = []

    for i in num:
        while stack and k > 0 and peek(stack) > i:
            pop(stack)
            k -= 1
        push(stack, i)

    while k > 0:
        pop(stack)
        k -= 1

    result = ''.join(stack).lstrip('0')
    return result if result else "0"

# Fixed input
num = "1432219"
k = 3
result = remove_k_digits(num, k)
print(result)
