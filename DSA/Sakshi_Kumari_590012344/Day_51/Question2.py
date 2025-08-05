def smallest_subarray_with_sum_greater_than_x(arr, x):
    n = len(arr)
    if n == 0:
        return 0

    start = 0
    end = 0
    current_sum = 0
    min_length = n + 1

    while end < n:
        current_sum += arr[end]
        end += 1

        while current_sum > x:
            window_length = end - start
            if window_length < min_length:
                min_length = window_length

            current_sum -= arr[start]
            start += 1

    if min_length == n + 1:
        return 0
    return min_length
