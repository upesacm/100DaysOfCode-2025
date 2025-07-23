stack = [1, 2, 3, 4, 5]
def push(num):
    stack.append(num)

def pop():
    return stack.pop()
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
def insert_bottom(num):
    global stack
    if not stack:
        stack.append(num)
    else:
        temp = pop()
        insert_bottom(num)
        push(temp)
    return stack

#Fixed Input
s = 8
print(insert_bottom(s))

#Custom Input
s = int(input("Enter the element : "))
print(insert_bottom(s))
