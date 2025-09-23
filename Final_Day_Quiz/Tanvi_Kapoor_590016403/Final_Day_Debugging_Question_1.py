from collections import deque

def sliding_window_max(arr, k):
    if not arr or k <= 0:
        return []

    result = []
    dq = deque()  # Stores indices

    for i in range(len(arr)):
        # Remove elements out of current window
        while dq and dq[0] <= i - k:
            dq.popleft()

        # Remove smaller elements (they'll never be max)
        while dq and arr[dq[-1]] < arr[i]:
            dq.pop()

        dq.append(i)

        # Append max of current window
        if i >= k - 1:
            result.append(arr[dq[0]])

    return result


# ---------------------------
# 🔍 Test Cases:
arr1 = [1, 3, -1, -3, 5, 3, 6, 7]
k1 = 3
result1 = sliding_window_max(arr1, k1)
print(f"Result: {result1}")  # Expected: [3, 3, 5, 5, 6, 7]

# Edge case:
arr2 = [4, 2, 1, 5]
k2 = 2
result2 = sliding_window_max(arr2, k2)
print(f"Edge case result: {result2}")  # Expected: [4, 2, 5]
