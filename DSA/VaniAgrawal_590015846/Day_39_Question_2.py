# Use a monotonic stack to efficiently compute stock price spans by tracking previous higher prices for optimal time-series analysis.
stack = []
min_stack = []

def push(x):
    stack.append(x)
    if not min_stack or x <= min_stack[-1]:
        min_stack.append(x)

def pop():
    if stack:
        if stack[-1] == min_stack[-1]:
            min_stack.pop()
        return stack.pop()

def get_min():
    return min_stack[-1] if min_stack else None

n = int(input("Enter number of operations: "))
for _ in range(n):
    cmd = input("Enter operation (push x / pop / get_min): ").split()
    if cmd[0] == 'push':
        push(int(cmd[1]))
    elif cmd[0] == 'pop':
        print("Popped:", pop())
    elif cmd[0] == 'get_min':
        print("Min:", get_min())
