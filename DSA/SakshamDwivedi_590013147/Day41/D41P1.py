stack = []
maxStack = []

def push(stack, num):
    stack.append(num)
    if not maxStack or num >= maxStack[-1]:
        maxStack.append(num)
    else:
        maxStack.append(maxStack[-1])

def pop(stack):
    if stack:
        maxStack.pop()
        return stack.pop()
    return None

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
def remove_adjacent_duplicates(s):
    global stack
    stack = []

    for i in s:
        if stack and peek(stack) == i:
            pop(stack)
        else:
            push(stack, i)

    return ''.join(stack)

#Fixed Input
s = "abbaca"
result = remove_adjacent_duplicates(s)
print(result)
