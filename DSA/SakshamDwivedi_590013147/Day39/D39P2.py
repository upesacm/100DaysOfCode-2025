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

def calculate_span(prices):
    span = [0] * len(prices)
    stack = []
    for i in range(len(prices)):
        while(stack and (prices[stack[-1]] <= prices[i])):
            pop(stack)
        if not stack:
            span[i] = i + 1
        else:
            span[i] = i - stack[-1]
        push(stack, i)
    return span

# Fixed Input
prices = [100, 80, 60, 70, 60, 75, 85]
print(calculate_span(prices))

# Custom Input
prices = []
n = int(input("Enter the number of days: "))
for i in range(n):
    price = int(input("Enter price: "))
    push(prices, price)

spans = calculate_span(prices)
print(spans)
