stack = []
stack0 = []
def push(stack, num):
    stack.append(num)

def pop(stack):
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

def evaluate_postfix(expression):
    stack = []
    for token in expression:
        if token.isdigit():
            push(stack, int(token))
        else:
            b = pop(stack)
            a = pop(stack)     
            if token == '+':
                push(stack, a+b)
            elif token == '-':
                push(stack, a-b)
            elif token == '*':
                push(stack, a*b)
            elif token == '/':
                push(stack, int(a/b))     
    return stack[0]

#Fixed Input
expression = "231*+9-"
result = evaluate_postfix(expression)
print("Result : ", result)

#Custom Input
expression = input("Enter the expression : ")
result = evaluate_postfix(expression)
print("Result : ", result)
