def insert(stack, item):
    if not stack:
        stack.append(item)
        return
    temp = stack.pop()
    insert(stack, item)
    stack.append(temp)

def reverse_stack(stack):
    if not stack:
        return
    temp = stack.pop()
    reverse_stack(stack)
    insert(stack, temp)

if __name__ == "__main__":
    stack = list(map(int, input("Enter the elements of the stack top to bottom separated by spaces : ").split()))
    reverse_stack(stack)
    print(stack)
