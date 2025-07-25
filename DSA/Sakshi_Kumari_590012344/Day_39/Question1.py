Your task: Implement recursive stack reversal using only the implicit call stack as temporary 
storage while maintaining O(1) auxiliary space complexity.
  
def insert_at_bottom(stack, value):
    if not stack:
        stack.append(value)
        return
    top = stack.pop()
    insert_at_bottom(stack, value)
    stack.append(top)

def reverse_stack(stack):
    if not stack:
        return
    top = stack.pop()
    reverse_stack(stack)
    insert_at_bottom(stack, top)
