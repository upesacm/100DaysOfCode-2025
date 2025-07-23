stack = []
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
def redundant_check(expression):
    for i in expression:
        if i == ")":
            operator_found = False
            top = pop(stack)
            while top != "(":
                if top in "+-*/":
                    operator_found = True
                top = pop(stack)

            if(operator_found == False):
                return "Redundant"
        else:
            push(stack, i)
    return "Non Redundant"

#Fixed Input
print(redundant_check("(1+(2+3))"))

#Custom Input
exp = input("Enter the expression : ")
print(redundant_check(exp))
