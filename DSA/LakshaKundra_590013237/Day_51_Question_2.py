def smallest_subarray_with_sum(arr, x):
    n = len(arr)
    min_len = n + 1
    curr_sum = 0
    start = 0

    for end in range(n):
        curr_sum += arr[end]

        while curr_sum > x:
            min_len = min(min_len, end - start + 1)
            curr_sum -= arr[start]
            start += 1

    return 0 if min_len == n + 1 else min_len

print(smallest_subarray_with_sum([1, 4, 45, 6, 0, 19], 51))  # Output: 3
print(smallest_subarray_with_sum([1, 10, 5, 2, 7], 9))       # Output: 1
