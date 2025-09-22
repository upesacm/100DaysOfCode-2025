def stack_max_sliding_window(arr, k):
    result = []
    for i in range(len(arr) - k + 1):
        window = arr[i:i+k]
        stack = []
        for num in window:
            while stack and stack[-1] < num:
                stack.pop()
            stack.append(num)
        result.append(stack[0])
    return result

# Example 1
arr1 = [1, 3, -1, -3, 5, 3, 6, 7]
k1 = 3
print(stack_max_sliding_window(arr1, k1))

# Example 2
arr2 = [4, 2, 1, 5]
k2 = 2
print(stack_max_sliding_window(arr2, k2))
