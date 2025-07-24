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

def reverse_rec(stack):
    if not stack:
        return
    temp = pop(stack)
    reverse_rec(stack)
    
    def push_bottom(s, val):
        if not s:
            push(s, val)
            return
        top = pop(s)
        push_bottom(s, val)
        push(s, top)

    push_bottom(stack, temp)


#Fixed Input
stack = [1,2,3,4,5]
reverse_rec(stack)
print(stack)

#Custom Input
stack = []
n = int(input("Enter the number of elements : "))
for i in range(n):
    element = int(input("Enter the number : "))
    push(stack, element)
reverse_rec(stack)
print(stack)
