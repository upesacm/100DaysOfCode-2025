def next_greater_element(arr):
    stack = []
    res = [-1] * len(arr)
    for i in range(len(arr) - 1, -1, -1):
        while stack and stack[-1] <= arr[i]:
            stack.pop()
        if stack:
            res[i] = stack[-1]
        stack.append(arr[i])
    return res

print(next_greater_element([4, 5, 2, 25]))
print(next_greater_element([13, 7, 6, 12]))
