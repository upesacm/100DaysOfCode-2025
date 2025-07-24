#Implement recursive stack reversal using only the implicit call stack as temporary storage while maintaining O(1) auxiliary space complexity.
def insert_at_bottom(stack, item):
    if len(stack) == 0:
        stack.append(item)
    else:
        temp = stack.pop()
        insert_at_bottom(stack, item)
        stack.append(temp)

def reverse_stack(stack):
    if len(stack) > 0:
        temp = stack.pop()
        reverse_stack(stack)
        insert_at_bottom(stack, temp)

input_str = input("Enter stack elements separated by space: ")
stack = list(map(int, input_str.strip().split()))

reverse_stack(stack)

print("Reversed Stack:")
print(stack)
