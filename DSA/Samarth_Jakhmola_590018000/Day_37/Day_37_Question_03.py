def delete_middle_element(stack, current = 0, size = None):
    if size is None:
        size = len(stack)

    if current == size // 2:
        stack.pop()
        return
    
    top = stack.pop()
    delete_middle_element(stack, current + 1, size)
    stack.append(top)

try:
    stack = list(map(int, input("Enter the elements of the stack separated by spaces : ").split()))
    delete_middle_element(stack)
    print(stack)
except:
    print("Invalid input. Please try with a valid input.")
