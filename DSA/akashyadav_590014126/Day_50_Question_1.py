def max_sum_subarray(arr, k):
    if len(arr) < k:
        return None 

    window_sum = sum(arr[:k])
    max_sum = window_sum

    for i in range(k, len(arr)):
        window_sum += arr[i] - arr[i - k]
        max_sum = max(max_sum, window_sum)

    return max_sum

# Example usage
print(max_sum_subarray([300, 400, 500, 600], 3))