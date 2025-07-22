def delete_middle(stack):
    """
    Deletes the middle element of a stack.
    """
    # Calculate the position of the middle element
    middle_pos = len(stack) // 2 + 1
    
    # Call the recursive utility function
    _delete_recursively(stack, middle_pos)

def _delete_recursively(stack, pos):
    """
    A recursive helper function to pop elements until the middle is reached.
    """
    # Base case: if the current position is 1, pop the element
    if pos == 1:
        stack.pop()
        return

    # Pop the top element and hold it in the call stack
    temp = stack.pop()
    
    # Recur for the remaining stack and decremented position
    _delete_recursively(stack, pos - 1)
    
    # Push the held element back onto the stack
    stack.append(temp)

# Test cases
stack1 = [1, 2, 3, 4, 5]
delete_middle(stack1)
print(stack1)

stack2 = [10, 20, 30]
delete_middle(stack2)
print(stack2)

stack3 = [1, 2, 3, 4]
delete_middle(stack3)
print(stack3)
