def is_max_heap(arr):
    n=len(arr)

    for i in range((n-2) // 2+1 ):
        left=2*i+1
        right=2*i+2

        if left < n and arr[i] <arr[left]:
            return False
        if right < n and arr[i] <arr[right]:
            return False
    
    return True

#example
arr1 = [99, 18, 11, 17, 21, 20]
print(is_max_heap(arr1)) 