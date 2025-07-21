stack = []
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
def balance_checker(brackets):
    match = {'}' : '{', ']' : '[', ')' : '('}
    global stack
    stack = []
    for i in brackets:
        if i in "({[":
            push(i)
        if i in "]})" and stack and match[i] == stack[-1]:
            pop()
    if stack:
        return "Unbalanced"
    else:
        return "Balanced"

#Fixed Input
s = "[{(})]"
print(balance_checker(s))

#Custom Input
s = input("Enter the brackets : ")
print(balance_checker(s))
