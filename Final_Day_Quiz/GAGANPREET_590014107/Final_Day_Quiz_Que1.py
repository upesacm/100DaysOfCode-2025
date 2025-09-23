#1. Identify the inefficiency in stack operations 
#-- The function uses a stack (list) but treats it like a queue.
#   stack.pop(0) removes the first element, which is O(n) time complexity because it shifts all remaining elements.
#    This defeats the purpose of using a stack, which is optimized for LIFO operations (append() and pop() from the end).

#2. Explain why stack.pop(0) is not optimal for stack-based approac
#-- Stacks are designed for operations at one end (top of stack).
#   pop(0) accesses the bottom of the stack, which is inefficient in Python lists
#Every pop(0) causes a full shift of elements — O(n) per operation, leading to O(n²) overall time complexity for large arrays.

#3. What should be the correct approach for maintaining sliding window with stack? 
from collections import deque

def max_sliding_window(arr, k):
    if not arr or k <= 0:
        return []

    result = []
    dq = deque()  # stores indices

    for i in range(len(arr)):
        # Remove indices out of current window
        while dq and dq[0] < i - k + 1:
            dq.popleft()

        # Remove smaller elements from the back
        while dq and arr[dq[-1]] < arr[i]:
            dq.pop()

        dq.append(i)

        # Add max for current window
        if i >= k - 1:
            result.append(arr[dq[0]])

    return result
