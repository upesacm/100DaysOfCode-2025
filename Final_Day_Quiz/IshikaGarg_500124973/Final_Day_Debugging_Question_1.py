1. Inefficiency in stack operations
The function recomputes the maximum by scanning all k elements each time → time complexity = O(n*k).
This defeats the whole purpose of a “stack-based” optimization.

2. Why stack.pop(0) is not optimal
In Python, list.pop(0) is O(n) because it shifts all remaining elements left by one index.
That means for each window, you’re paying an extra O(n), leading to O(n²) worst case when combined with scanning for max.
A real stack is LIFO (last-in, first-out), so popping from index 0 breaks the intended stack behavior.

3. Correct approach for maintaining sliding window with stack
The standard optimized solutions use:
Deque (double-ended queue), not a stack.
Maintain indices in decreasing order of values.
Front of deque always stores the max of the current window.
Before adding a new element, pop smaller elements from the back.
Before moving to next window, pop indices from the front if they are out of range.
Complexity = O(n)


Corrected code:
from collections import deque

def max_sliding_window(arr, k):
    if not arr or k <= 0:
        return []
    
    dq = deque()  # will store indices
    result = []
    
    for i in range(len(arr)):
        # Remove elements outside the current window
        if dq and dq[0] <= i - k:
            dq.popleft()
        
        # Maintain decreasing order in deque
        while dq and arr[dq[-1]] < arr[i]:
            dq.pop()
        
        dq.append(i)
        
        # Record max once window is full
        if i >= k - 1:
            result.append(arr[dq[0]])
    
    return result
