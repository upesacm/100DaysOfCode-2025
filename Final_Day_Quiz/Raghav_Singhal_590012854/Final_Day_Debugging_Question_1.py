from collections import deque

def max_sliding_window(arr, k):
    if not arr or k <= 0:
        return []
    dq = deque()   # stores indices, arr values decreasing
    res = []
    for i, x in enumerate(arr):
        # remove indices out of window
        while dq and dq[0] <= i - k:
            dq.popleft()
        # remove smaller values from back
        while dq and arr[dq[-1]] < x:
            dq.pop()
        dq.append(i)
        if i >= k - 1:
            res.append(arr[dq[0]])
    return res
