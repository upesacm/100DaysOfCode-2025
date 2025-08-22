def max_sum_subarray_k(arr, k):
    n = len(arr)
    if n < k:
        return None  # Not enough elements
    # Compute sum of first window
    window_sum = sum(arr[:k])
    max_sum = window_sum
    # Slide the window
    for i in range(k, n):
        window_sum += arr[i] - arr[i - k]
        max_sum = max(max_sum, window_sum)
    return max_sum

# Example usage:
print(max_sum_subarray_k([1, 4, 2, 10], 2))          
print(max_sum_subarray_k([100, 200, 300, 400], 2))    