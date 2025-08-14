def is_max_heap(arr):
    n = len(arr)
    
    # Only need to check internal nodes (0 to n//2 - 1)
    for i in range((n // 2)):
        left = 2 * i + 1
        right = 2 * i + 2
        
        # Check left child
        if left < n and arr[i] < arr[left]:
            return False
        
        # Check right child
        if right < n and arr[i] < arr[right]:
            return False
    
    return True

# Example usage
print(is_max_heap([90, 15, 10, 7, 12, 2]))  # True
print(is_max_heap([9, 15, 10, 7, 12, 2]))   # False
