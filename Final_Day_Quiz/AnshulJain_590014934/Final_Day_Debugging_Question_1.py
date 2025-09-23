def stack_max_window(arr, k):
    if not arr or k <= 0:
        return []

    result = []
    stack = []

    for i in range(len(arr)):
        stack.append(arr[i])
        if len(stack) == k:
            max_val = stack[0]
            for val in stack:
                if val > max_val:
                    max_val = val
            result.append(max_val)
            stack.pop(0)
    return result

arr1 = [1, 3, -1, -3, 5, 3, 6, 7]
k1 = 3
result1 = stack_max_window(arr1, k1)
print(f"Result: {result1}")

arr2 = [4, 2, 1, 5]
k2 = 2
result2 = stack_max_window(arr2, k2)
print(f"Edge case result: {result2}")

# Task answers:
# 1. Inefficiency: repeatedly scanning full window O(k) for max in each step makes total O(n*k).
# 2. stack.pop(0) is not optimal because it shifts all remaining elements, costing O(n) per operation.
# 3. Correct approach: use a deque (double-ended queue) to maintain indices of useful elements, achieving O(n) complexity. 
