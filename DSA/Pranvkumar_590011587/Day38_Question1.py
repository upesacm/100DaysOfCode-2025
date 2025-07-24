def next_greater_element(arr):
    n = len(arr)
    res = [-1] * n
    stack = []
    for i in range(n - 1, -1, -1):
        while stack and stack[-1] <= arr[i]:
            stack.pop()
        res[i] = stack[-1] if stack else -1
        stack.append(arr[i])
    return res

# Examples
print(next_greater_element([4, 5, 2, 25]))   
print(next_greater_element([13, 7, 6, 12]))  