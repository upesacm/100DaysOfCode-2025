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
def is_celebrity(M, n):
    for i in range(n):
        push(stack, i)

    while len(stack) > 1:
        a = pop(stack)
        b = pop(stack)

        if M[a][b]:
            push(stack, b)
        else:
            push(stack, a)

    if not stack:
        return "No celebrity!"

    c = pop(stack)
    for i in range(n):
        if i == c:
            continue
        if M[c][i] or not M[i][c]:
            return "No celebrity!"
    return c

#Fixed Input
matrix = [[0, 1, 1],[0, 0, 1],[0, 0, 0]]
print(is_celebrity(matrix, 3))
