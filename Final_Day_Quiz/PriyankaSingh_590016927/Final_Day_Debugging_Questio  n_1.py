from collections import deque

def max_sliding_window(arr, k):
    if not arr or k <= 0:
        return []

    result = []
    dq = deque()  # store indices

    for i in range(len(arr)):
        # Remove indices out of the current window
        while dq and dq[0] < i - k + 1:
            dq.popleft()

        # Remove smaller elements from the back
        while dq and arr[dq[-1]] < arr[i]:
            dq.pop()

        dq.append(i)

        # Append max value for current window
        if i >= k - 1:
            result.append(arr[dq[0]])

    return result

# Test cases
arr1 = [1, 3, -1, -3, 5, 3, 6, 7]
k1 = 3
print("Result:", max_sliding_window(arr1, k1))
# Expected: [3, 3, 5, 5, 6, 7]

arr2 = [4, 2, 1, 5]
k2 = 2
print("Edge case result:", max_sliding_window(arr2, k2))
# Expected: [4, 2, 5]
