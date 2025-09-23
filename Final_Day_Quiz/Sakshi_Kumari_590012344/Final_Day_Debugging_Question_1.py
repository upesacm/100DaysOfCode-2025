from collections import deque

def stack_max_window(arr, k):
    if not arr or k <= 0:
        return []
    
    result = []
   
    window = deque()
    
    for i in range(len(arr)):
     
        window.append(arr[i])
       
        if len(window) > k:
            window.popleft()
        
       
        if len(window) == k:
            result.append(max(window))  
    
    return result
