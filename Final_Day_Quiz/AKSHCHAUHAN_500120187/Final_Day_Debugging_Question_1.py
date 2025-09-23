from collections import deque

def max_sliding_window(arr, k):
    if not arr or k <= 0:
        return []

    dq = deque()  # stores indices
    result = []

    for i in range(len(arr)):
        # Remove elements out of window
        while dq and dq[0] <= i - k:
            dq.popleft()

        # Maintain decreasing order in deque
        while dq and arr[dq[-1]] < arr[i]:
            dq.pop()

        dq.append(i)

        # Add maximum for each full window
        if i >= k - 1:
            result.append(arr[dq[0]])

    return result
