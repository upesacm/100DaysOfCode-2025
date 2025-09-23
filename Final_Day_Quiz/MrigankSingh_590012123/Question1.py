from collections import deque

def stack_max_window(arr, k):
    if not arr or k <= 0:
        return []
    
    result = []
    # Use deque for efficient front/back operations
    window = deque()
    
    for i in range(len(arr)):
        # Add current element
        window.append(arr[i])
        
        # Maintain window size
        if len(window) > k:
            window.popleft()
        
        # If we have a complete window
        if len(window) == k:
            result.append(max(window))  # Or use optimized max tracking
    
    return result
