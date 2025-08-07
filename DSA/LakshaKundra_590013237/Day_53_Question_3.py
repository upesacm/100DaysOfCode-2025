def longest_mountain(arr):
    n = len(arr)
    longest = 0
    i = 1
    while i < n - 1:
        if arr[i - 1] < arr[i] > arr[i + 1]:
            left = i - 1
            while left > 0 and arr[left - 1] < arr[left]:
                left -= 1
            right = i + 1
            while right < n - 1 and arr[right] > arr[right + 1]:
                right += 1
            longest = max(longest, right - left + 1)
            i = right
        else:
            i += 1
    return longest

print(longest_mountain([2,1,4,7,3,2,5]))  # 5
print(longest_mountain([2,2,2]))          # 0
