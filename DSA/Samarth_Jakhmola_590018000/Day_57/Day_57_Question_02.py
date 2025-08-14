def check_max_heap(arr):
    n = len(arr)
    # We only need to check non - leaf nodes
    for i in range((n // 2) - 1, -1, -1):
        left = 2 * i + 1
        right = 2 * i + 2

        # Check left child
        if left < n and arr[i] < arr[left]:
            return False
        # Check right child
        if right < n and arr[i] < arr[right]:
            return False
    
    return True

try:
    arr = list(map(int, input("Enter the elements of the array : ").split()))
    print(check_max_heap(arr))
except:
    print("Invalid input. Please try with a valid input.")
