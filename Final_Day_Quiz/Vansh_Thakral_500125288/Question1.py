1) Inefficiency in stack operations
The code uses stack.pop(0) to remove the first element of the window. In Python lists this is O(n) because removing the first element shifts all remaining elements left.
The code also finds the max by scanning the whole stack for every window (for val in stack), which is O(k) per window.
Combined, each slide costs Θ(k) (scan) + Θ(k) (shift) → overall O(n * k) worst-case time complexity. This is inefficient for large n and k.

2) Why stack.pop(0) is not optimal here
A Python list is an array-backed sequence: pop(0) shifts all elements and is O(n).
Using pop(0) on something you called stack is semantically wrong anyway: stacks pop from the end. pop(0) is a queue-like removal (front), not a stack operation.
For sliding-window algorithms you want O(1) removals from the front — either use collections.deque.popleft() (O(1)) or better use a monotonic deque (see below).
Repeated pop(0) leads to many element shifts and makes the implementation quadratic when combined with scanning.


from collections import deque

def max_sliding_window(nums, k):
    if not nums or k <= 0:
        return []
    dq = deque()  # store indices, values in decreasing order
    res = []
    for i, val in enumerate(nums):
        # 1) remove indices out of this window
        while dq and dq[0] <= i - k:
            dq.popleft()
        # 2) remove smaller values from the right (they can't be max if current val >= them)
        while dq and nums[dq[-1]] < val:
            dq.pop()
        # 3) add current index
        dq.append(i)
        # 4) append current window max
        if i >= k - 1:
            res.append(nums[dq[0]])
    return res
