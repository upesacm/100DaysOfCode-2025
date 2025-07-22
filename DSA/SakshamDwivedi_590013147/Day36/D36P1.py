stack = []
def push(num):
    stack.append(num)

def pop():
    return stack.pop()

'''
These are not needed right now but are basic stack functions.
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
def reverse(string):
    global stack
    stack = []
    rev = ""
    for i in string:
        push(i)
    for i in range(len(string)):
        rev += pop()
    return rev

#Fixed Input
s = "Hello"
print(reverse(s))

#Custom Input
s = input("Enter the string : ")
print(reverse(s))
