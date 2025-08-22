def max_sum_subarray(arr, k):
    if len(arr) < k:
        return None  # Not enough elements for the window size
    window_sum = sum(arr[:k])
    max_sum = window_sum
    for i in range(k, len(arr)):
        window_sum += arr[i] - arr[i - k]  # Slide the window
        if window_sum > max_sum:
            max_sum = window_sum
    return max_sum

# Example usage:
arr1 = [1, 4, 2, 10]
k1 = 2
print(max_sum_subarray(arr1, k1))  # Output: 12

arr2 = [100, 200, 300, 400]
k2 = 2
print(max_sum_subarray(arr2, k2))  # Output: 700
