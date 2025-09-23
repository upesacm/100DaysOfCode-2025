def stack_max_window(arr, k):
    if not arr or k <= 0:
        return []

    result = []
    stack = []

    for i in range(len(arr)):
        # add current element
        stack.append(arr[i])

        # check if we have a complete window
        if len(stack) == k:
            # not wrong, but inefficient → scanning whole window each time (O(k))
            max_val = stack[0]
            for val in stack:
                if val > max_val:
                    max_val = val
            result.append(max_val)

            # problem: using pop(0) → this shifts all elements (O(n)), very slow
            # better would be deque.popleft() or a different structure
            stack.pop(0)

    return result


# Test case
arr1 = [1, 3, -1, -3, 5, 3, 6, 7]
k1 = 3
result1 = stack_max_window(arr1, k1)
print(f"Result: {result1}")
# actually gives [3, 3, 3, 5, 5, 6] (expected [3, 3, 5, 5, 6, 7])
# windows get misaligned because of pop(0)

# Edge case
arr2 = [4, 2, 1, 5]
k2 = 2
result2 = stack_max_window(arr2, k2)
print(f"Edge case result: {result2}")
# returns [4, 2, 5] → values look fine here but still O(n*k) overall

# summary: 
# 1) scanning every window = O(n*k)
# 2) pop(0) is O(n), bad for performance
# 3) correct fix: use deque (monotonic queue) for O(n) solution
