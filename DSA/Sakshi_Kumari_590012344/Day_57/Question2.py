def is_max_heap(arr):
    n = len(arr)
    i = 0
    while i < (n // 2):
        left = 2 * i + 1
        right = 2 * i + 2
        if left < n and arr[i] < arr[left]:
            return False
        if right < n and arr[i] < arr[right]:
            return False
        i = i + 1
    return True
