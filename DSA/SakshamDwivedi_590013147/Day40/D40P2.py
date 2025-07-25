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
def largest_rectangle_area(bars):
    n = len(bars)
    st = []
    res = 0
    
    i = 0
    while i < n:
        if not st or bars[i] >= bars[st[-1]]:
            push(st, i)
            i += 1
        else:
            top = pop(st)
            if not st:
                w = i
            else:
                w = i - st[-1] - 1
            temp = bars[top] * w
            res = max(res, temp)
            # print('area?', temp)

    while st:
        top = pop(st)
        if not st:
            w = i
        else:
            w = i - st[-1] - 1
        temp = bars[top] * w
        res = max(res, temp)

    return res

#Fixed Input
print(largest_rectangle_area([2,1,5,6,2,3]))
print(largest_rectangle_area([2,4]))

