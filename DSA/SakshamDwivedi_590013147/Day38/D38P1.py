input_stack = []
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
def next_greater_elements(arr):
    n = len(arr)
    result = [-1] * n
    stack = []
    for i in range(n - 1, -1, -1):
        while(stack and (arr[stack[-1]] <= arr[i])):
            pop(stack)
        if stack:
            result[i] = arr[stack[-1]]
        push(stack, i)

    return result

#Fixed Input
print(next_greater_elements([4, 2, 5, 25]))

#Custom Input
n = int(input("Enter the number of elements : "))
for i in range(n):
    element = int(input("Enter the number : "))
    push(input_stack, element)
print(next_greater_elements(input_stack))
