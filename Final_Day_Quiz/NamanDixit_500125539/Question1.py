#1. Linear Search for Maximum: For each window of size k, the code iterates through the entire window (stack)
#  to find the maximum value,which takes O(k) time per window. With n - k + 1 windows, this contributes to a
#  total time complexity of O(n*k).
#Popping from the Front: The stack.pop(0) operation removes the first element of the list to slide the window.
#In Python, lists are array-based, so removing the first element requires shifting all subsequent elements,
#which takes O(k) time per operation.


#2.List Implementation: In Python, a list is implemented as a dynamic array. Removing the first element (pop(0))
# requires shifting all remaining elements one position to the left, which has a time complexity of O(k) for a list of size k.
#Mismatch with Stack Semantics: A stack typically supports O(1) push and pop operations at the end of the stack (LIFO: Last In, First Out).
# Using pop(0) treats the list like a queue (FIFO: First In, First Out), which is not optimal for a stack-based approach and defeats the
#purpose of using a stack for constant-time operations at one end.
#Cumulative Impact: Since pop(0) is called for each of the n - k + 1 windows, the total cost of these operations is O(n*k), significantly
#increasing the runtime for large arrays or window sizes.


#3.Corrected code:- 
from collections import deque

def stack_max_window(arr, k):
    if not arr or k <= 0:
        return []
    
    result = []
    deq = deque()
    
    for i in range(len(arr)):
        # Remove smaller elements from the back
        while deq and arr[deq[-1]] <= arr[i]:
            deq.pop()
        
        # Add current element's index
        deq.append(i)
        
        # Remove indices outside the current window
        while deq and deq[0] <= i - k:
            deq.popleft()
        
        # If window size is k, add max (element at front of deque)
        if i >= k - 1:
            result.append(arr[deq[0]])
    
    return result

# Test cases
arr1 = [1, 3, -1, -3, 5, 3, 6, 7]
k1 = 3
print(f"Result: {stack_max_window(arr1, k1)}")  # Output: [3, 3, 5, 5, 6, 7]

arr2 = [4, 2, 1, 5]
k2 = 2
print(f"Edge case result: {stack_max_window(arr2, k2)}")  # Output: [4, 2, 5]
