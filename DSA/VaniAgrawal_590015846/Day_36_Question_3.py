# Insert an element at the stack's bottom position using recursive operations while maintaining the original order of existing elements. 
def insert_at_bottom(stack, x):
    if not stack:
        stack.append(x)
        return
    temp = stack.pop()
    insert_at_bottom(stack, x)
    stack.append(temp)

def main():
    stack_input = input("Enter stack elements separated by space: ")
    x = int(input("Enter element to insert at bottom: "))
    
    stack = list(map(int, stack_input.split()))
    
    insert_at_bottom(stack, x)
    print("Modified stack:", stack)

main()
