
arr = list(map(int, input("Enter array elements separated by space: ").split()))

def is_max_heap(arr):
    n = len(arr)
    for i in range((n - 2) // 2 + 1):  
        left = 2 * i + 1
        right = 2 * i + 2
        
        if left < n and arr[i] < arr[left]:
            return False
        if right < n and arr[i] < arr[right]:
            return False
    return True

print("true" if is_max_heap(arr) else "false")
