#answer 1
#Inefficiency → pop(0) makes the algorithm O(n*k)

#answer 2
#Not optimal → stack should only pop from the end, pop(0) breaks efficiency.

#answer 3
#Correct approach → use a deque to maintain the sliding window in O(n).

from collections import deque

def stack_max_window(arr, k):
    if not arr or k <= 0:
        return []

    result = []
    dq = deque()

    for i in range(len(arr)):
        while dq and dq[0] <= i - k:
            dq.popleft()
        while dq and arr[dq[-1]] < arr[i]:
            dq.pop()
        dq.append(i)
        if i >= k - 1:
            result.append(arr[dq[0]])
    return result

arr1 = [1, 3, -1, -3, 5, 3, 6, 7]
k1 = 3
result1 = stack_max_window(arr1, k1)
print(f"Result: {result1}")

arr2 = [4, 2, 1, 5]
k2 = 2
result2 = stack_max_window(arr2, k2)
print(f"Edge case result: {result2}")
