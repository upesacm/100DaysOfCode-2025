def longestMountain(arr):
    n = len(arr)
    max_len = 0
    i = 1
    while i < n - 1:
        if arr[i-1] < arr[i] > arr[i+1]:  # Peak
            left = i - 1
            right = i + 1
            while left > 0 and arr[left-1] < arr[left]:
                left -= 1
            while right < n - 1 and arr[right] > arr[right+1]:
                right += 1
            max_len = max(max_len, right - left + 1)
            i = right
        else:
            i += 1
            
    return max_len

print(longestMountain([2, 1, 4, 7, 3, 2, 5])) 
print(longestMountain([2, 2, 2]))           