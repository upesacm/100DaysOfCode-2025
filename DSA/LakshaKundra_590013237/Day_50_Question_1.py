def max_sum_subarray(arr, k):
    n = len(arr)
    if n < k:
        return 0
    window_sum = sum(arr[:k])
    max_sum = window_sum
    for i in range(k, n):
        window_sum += arr[i] - arr[i - k]
        max_sum = max(max_sum, window_sum)
    return max_sum

print(max_sum_subarray([1, 4, 2, 10], 2))       # Output: 12
print(max_sum_subarray([100, 200, 300, 400], 2)) # Output: 700
