def smallest_subarray_with_sum(arr, x):
    n = len(arr)
    min_len = n + 1
    curr_sum = 0
    left = 0

    for right in range(n):
        curr_sum += arr[right]

        while curr_sum > x:
            min_len = min(min_len, right - left + 1)
            curr_sum -= arr[left]
            left += 1

    return min_len if min_len <= n else 0
