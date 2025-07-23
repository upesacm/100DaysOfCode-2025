def delete_middle(stack, current, mid):
    if current == mid:
        stack.pop()
        return
    val = stack.pop()
    delete_middle(stack, current + 1, mid)
    stack.append(val)

stack = list(map(int, input().split()))
mid = len(stack) // 2
delete_middle(stack, 0, mid)
print(*stack)
