#   For test case arr1 : The actual output is also the same, i.e., [3, 3, 5, 5, 6, 7]. The reason is that though inefficient, the naive
#                        max-finding still works correctly here.
# 
# 
#   For test case arr2 : The actual output is [4, 2, 5] as it still works correctly but inefficient because of repeated scanning and 
#                        pop(0).
# 
# 
#   1.  Inefficiency in stack operations :
#       - The function scans the entire window (size k) every time to find the max -> O(k) per window.
#       -It also calls stack.pop(0), which is O(k) because it shifts all elements in a Python list.
#       - So overall time complexity becomes O(n*k), which is inefficient. 
# 
# 
#   2.  stack.pop(0) is not optimal for stack-based approach as : 
#       - pop(0) is not O(1), it requires shifting elements to the left.
#       - in a true stack, we should only remove from the top (end), not the beginning. 
#       - using pop(0) repeatedly breaks stack semantics and slows down sliding operations. 
# 
# 
#   3.  The correct approach for maintaining sliding window with stack is :
#       - Use a monotonic deque (double-ended queue) of indices to track maximums.
#       - Remove indices that fall out of the current window from the left. 
#       - Remove smaller elements from the right so the deque remains decreasing.
#       - The front of the deque always gives the maximum in O(1).
