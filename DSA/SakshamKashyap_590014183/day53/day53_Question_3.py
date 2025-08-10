def longest_mountain(arr):
    n = len(arr)
    max_len = 0
    i = 1

    while i < n - 1:
        # Check peak
        if arr[i - 1] < arr[i] > arr[i + 1]:
            # expand left
            left = i - 1
            while left > 0 and arr[left - 1] < arr[left]:
                left -= 1
            # expand right
            right = i + 1
            while right < n - 1 and arr[right] > arr[right + 1]:
                right += 1
            max_len = max(max_len, right - left + 1)
            i = right  # Move to end of current mountain
        else:
            i += 1
    return max_len

# Example usage:
print(longest_mountain([2,1,4,7,3,2,5]))  # Output: 5
print(longest_mountain([2,2,2]))          # Output: 0
