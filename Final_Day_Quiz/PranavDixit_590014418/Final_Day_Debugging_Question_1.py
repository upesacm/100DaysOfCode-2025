from collections import deque

def sliding_max(arr, k):
    if not arr or k <= 0:
        return []
    dq = deque()
    res = []
    for i, v in enumerate(arr):
        while dq and dq[0] <= i - k:
            dq.popleft()
        while dq and arr[dq[-1]] < v:
            dq.pop()
        dq.append(i)
        if i >= k - 1:
            res.append(arr[dq[0]])
    return res

if __name__ == "__main__":
    arr1 = [1, 3, -1, -3, 5, 3, 6, 7]
    k1 = 3
    print("Result:", sliding_max(arr1, k1))

    arr2 = [4, 2, 1, 5]
    k2 = 2
    print("Edge case result:", sliding_max(arr2, k2))

"""
Answers:
1. Inefficiency: using a Python list with pop(0) which is O(n) per removal.
2. pop(0) is not optimal because it shifts all elements and makes the sliding operation O(n) instead of O(1).
3. Correct approach: use a monotonic deque holding indices (values in decreasing order). Remove indices out of the current window from the front, and remove smaller elements from the back before appending the new index. The front of the deque is the window maximum.
"""
