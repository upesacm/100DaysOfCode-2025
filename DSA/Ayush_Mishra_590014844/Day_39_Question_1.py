def insert_bottom(stack, val):
    if not stack:
        stack.append(val)
        return
    top = stack.pop()
    insert_bottom(stack, val)
    stack.append(top)

def reverse(stack):
    if not stack:
        return
    top = stack.pop()
    reverse(stack)
    insert_bottom(stack, top)

n = int(input())
stack = list(map(int, input().split()))
reverse(stack)
print(*stack)
