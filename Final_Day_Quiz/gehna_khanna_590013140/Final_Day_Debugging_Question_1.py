#1.Inefficiency: Each window recomputes max in O(k) and uses pop(0) which is O(n), making overall O(n·k).
#2.Why pop(0) bad: Python lists shift all elements left → inefficient.
#Correct approach: Use a monotonic deque (store indices, maintain decreasing order) to get sliding window max in O(n).
#correct code-
from collections import deque

def max_sliding_window(nums, k):
    if not nums or k <= 0:
        return []
    if k == 1:
        return nums[:]  # trivial

    dq = deque()   # will store indices, arr[dq] is decreasing
    res = []

    for i, val in enumerate(nums):
        # 1) remove indices outside window
        if dq and dq[0] <= i - k:
            dq.popleft()

        # 2) maintain decreasing order: remove smaller values from back
        while dq and nums[dq[-1]] < val:
            dq.pop()

        dq.append(i)

        # 3) window is complete -> take the front as max
        if i >= k - 1:
            res.append(nums[dq[0]])

    return res

# Example runs:
arr1 = [1, 3, -1, -3, 5, 3, 6, 7]
print(max_sliding_window(arr1, 3))  # -> [3, 3, 5, 5, 6, 7]

arr2 = [4, 2, 1, 5]
print(max_sliding_window(arr2, 2))  # -> [4, 2, 5]
