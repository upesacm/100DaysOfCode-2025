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
'''
These are not required but are basic stack functions.
def peek():
    if stack:
        print(stack[-1])
    else:
        print("Stack is empty!")

def display():
    if stack:
        print(stack)
    else:
        print("Stack is empty!")
'''
def getMax():
    if maxStack:
        return maxStack[-1]
    return None

#Fixed Input
push(stack, 3)
push(stack, 5)
push(stack, 2)
print(getMax())

pop(stack)
print(getMax())

pop(stack)
print(getMax())
