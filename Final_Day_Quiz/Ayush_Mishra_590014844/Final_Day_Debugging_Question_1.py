def stack_max_window(arr, k):
    if not arr or k <= 0:
        return []

    result = []
    stack = []

    for i in range(len(arr)):
        #add current element to stack
        stack.append(arr[i])

        #if we have a complete window
        if len(stack) == k:
            # corrected:find maximum in current window
            max_val = stack[0]
            for val in stack:
                if val > max_val:
                    max_val = val
            result.append(max_val)

            #corrected: efficient removal using deque
            from collections import deque
            stack = deque(stack)
            stack.popleft()
            stack = list(stack)

    return result


#test case:
arr1 = [1, 3, -1, -3, 5, 3, 6, 7]
k1 = 3
result1 = stack_max_window(arr1, k1)
print(f"Result: {result1}")
# expected: [3, 3, 5, 5, 6, 7]

# edge case:
arr2 = [4, 2, 1, 5]
k2 = 2
result2 = stack_max_window(arr2, k2)
print(f"Edge case result: {result2}")
# expected: [4, 2, 5]
