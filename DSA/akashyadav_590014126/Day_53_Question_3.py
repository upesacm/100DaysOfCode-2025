def longestMountain(arr):
    n = len(arr)
    maxLength = 0
    i = 1

    while i < n - 1:
        # Check if arr[i] is a peak
        if arr[i - 1] < arr[i] > arr[i + 1]:
            left = i - 1
            right = i + 1

            # Expand left
            while left > 0 and arr[left - 1] < arr[left]:
                left -= 1

            # Expand right
            while right < n - 1 and arr[right] > arr[right + 1]:
                right += 1

            # Update maxLength
            maxLength = max(maxLength, right - left + 1)
            i = right  # Skip to end of current mountain
        else:
            i += 1

    return maxLength
