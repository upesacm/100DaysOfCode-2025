stack = []
min_stack = []

def push(stack, num):
    stack.append(num)
    if not min_stack:
        min_stack.append(num)
    else:
        min_stack.append(min(num, min_stack[-1]))

def pop(stack):
    if stack:
        min_stack.pop() 
        return stack.pop()
    return None

def get_min():
    if min_stack:
        return min_stack[-1]
    return None

#Fixed Input
push(stack, 5)
push(stack, 3)
push(stack, 8)
push(stack, 10)
push(stack, 1)
push(stack, 7)
print(get_min())
pop(stack)
print(get_min())
pop(stack)
print(get_min())


#Custom Input
stack = []
con = "y"
while con == "y" or con == "Y":
    choice = int(input("Press 1 for push, 2 for pop, 3 for get min : "))
    match choice:
        case 1:
            num = int(input("Enter the number to push : "))
            push(stack, num)
            print(stack)
            
        case 2:
            pop(stack)
            print(stack)
            
        case 3:
            print(get_min())
            
        case _:
            print("Invalid Input")
    
    con = input("Enter Y to continue or N to exit : ")
