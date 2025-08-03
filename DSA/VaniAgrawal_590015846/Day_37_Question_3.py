# Implement recursive stack operations to locate and remove the middle element while maintaining the original order of all other elements
def delete_middle(stack):
    mid = len(stack) // 2
    del stack[mid]
    return stack

stack = list(map(int, input("Enter stack elements (space separated): ").split()))
print("Stack after deleting middle element:", delete_middle(stack))
