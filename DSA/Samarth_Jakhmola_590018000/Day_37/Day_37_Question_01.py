def sort_stack(stack):
    temp_stack = []

    while stack:
        current = stack.pop()

        while temp_stack and temp_stack[-1] > current:
            stack.append(temp_stack.pop())

        temp_stack.append(current)

    return temp_stack

try:
    stack = list(map(int, input("Enter the elements of the stack separated by spaces : ").split()))
    print(sort_stack(stack))
except:
    print("Invalid input. Please try with a valid input.")
