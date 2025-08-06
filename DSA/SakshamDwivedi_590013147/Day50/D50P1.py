def max_sum_subarray(arr, k):
    n = len(arr)
    if n < k:
        return None

    window_sum = sum(arr[:k])
    max_sum = window_sum

    for i in range(k, n):
        window_sum += arr[i] - arr[i - k]
        max_sum = max(max_sum, window_sum)

    return max_sum

#Fixed Input
arr = [1, 4, 2, 10]
k = 2
print(max_sum_subarray(arr, k))
