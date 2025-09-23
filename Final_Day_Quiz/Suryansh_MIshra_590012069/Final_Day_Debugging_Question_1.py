from collections import deque

def max_sliding_window(nums, k):
    if not nums or k <= 0:
        return []
    dq = deque()         # store indices, values in decreasing order
    out = []
    for i, x in enumerate(nums):
        # evict indices left of window
        if dq and dq[0] <= i - k:
            dq.popleft()
        # maintain decreasing order
        while dq and nums[dq[-1]] < x:
            dq.pop()
        dq.append(i)
        # record max once window size reached
        if i >= k - 1:
            out.append(nums[dq[0]])
    return out
