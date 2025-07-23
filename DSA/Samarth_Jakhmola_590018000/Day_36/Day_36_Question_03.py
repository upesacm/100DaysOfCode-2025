def insert_at_bottom(stack, x):
    if not stack:
        stack.append(x)
        return 
    
    top = stack.pop()

    insert_at_bottom(stack, x)

    stack.append(top)

try:
    stack = list(map(int, input("Enter the elements of the stack separated by spaces : ").split()))
    x = int(input("Enter the element which to be inserted at the bottom of the stack : "))
    insert_at_bottom(stack, x)
    print(stack)
except:
    print("Invalid input. Please try with a valid input.")
