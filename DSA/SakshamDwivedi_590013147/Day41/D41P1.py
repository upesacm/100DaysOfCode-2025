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
