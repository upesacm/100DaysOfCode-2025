#Implement recursive stack reversal using only the implicit call stack as temporary storage while maintaining O(1) auxiliary space complexity.
def next_greater_elements(arr):
    stack = []
    res = [-1] * len(arr)

    for i in range(len(arr) - 1, -1, -1):
        while stack and stack[-1] <= arr[i]:
            stack.pop()
        if stack:
            res[i] = stack[-1]
        stack.append(arr[i])
    return res

arr = list(map(int, input("Enter array elements: ").split()))
print("Next greater elements:", next_greater_elements(arr))
