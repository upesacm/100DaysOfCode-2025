def delete_middle(stack, k):
    if k == 1:
        stack.pop()
        return
    temp = stack.pop()
    delete_middle(stack, k - 1)
    stack.append(temp)

def remove_middle(stack):
    k = (len(stack) + 1) // 2
    delete_middle(stack, k)
    return stack

print(remove_middle([1, 2, 3, 4, 5]))   # Output: [1, 2, 4, 5]
print(remove_middle([10, 20, 30]))      # Output: [10, 30]
