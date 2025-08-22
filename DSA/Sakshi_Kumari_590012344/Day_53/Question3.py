def longest_mountain(arr):
    n = len(arr)
    max_length = 0
    i = 1

    while i < n - 1:
        if arr[i - 1] < arr[i] > arr[i + 1]:
            left = i - 1
            while left > 0 and arr[left - 1] < arr[left]:
                left -= 1

            right = i + 1
            while right < n - 1 and arr[right] > arr[right + 1]:
                right += 1

            mountain_length = right - left + 1
            max_length = max(max_length, mountain_length)
            i = right
        else:
            i += 1

    return max_length
