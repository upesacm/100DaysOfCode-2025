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

def sort_stack():
    global stack, stack0
    while stack:
        temp = pop(stack)
        while stack0 and stack0[-1] > temp:
            push(stack, pop(stack0))
        push(stack0, temp)
    return stack0

# Fixed Input Test
stack = [3, 4, 1, 8, 6, 5]
stack0 = []
print("Sorted stack :", sort_stack())

# Custom Input
stack = []
stack0 = []
n = int(input("Enter number of elements: "))
for i in range(n):
    element = int(input("Enter element: "))
    push(stack, element)

print("Sorted stack :", sort_stack())
