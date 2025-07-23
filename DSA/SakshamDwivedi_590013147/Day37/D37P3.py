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

def delete_middle(stack, current=0, n=None):
    if n is None:
        n = len(stack)
    
    if current == n // 2:
        pop(stack)
        return
    
    temp = pop(stack)
    delete_middle(stack, current + 1, n)
    push(stack, temp)

#Fixed Input
stack = [1, 2, 3, 4, 5]
print("Before :", stack)
delete_middle(stack)
print("After :", stack)

#Custom Input
stack = []
n = int(input("Enter number of elements in the stack: "))
for i in range(n):
    element = int(input("Enter element: "))
    push(stack, element)

print("Before :", stack)
delete_middle(stack)
print("After :", stack)
