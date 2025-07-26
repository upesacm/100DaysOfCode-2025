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

def decode_string(s):
    global stack
    stack = []

    for i in s:
        if i != ']':
            push(stack, i)
        else:
            temp = ""
            while stack and peek(stack) != '[':
                temp = pop(stack) + temp
            pop(stack)

            num_str = ""
            while stack and peek(stack).isdigit():
                num_str = pop(stack) + num_str
            repeat_count = int(num_str)

            expanded = temp * repeat_count
            for j in expanded:
                push(stack, j)

    return ''.join(stack)

#Fixed Input
s = "3[a]2[bc]"
result = decode_string(s)
print(result)
