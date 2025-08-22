def longest_subarray_with_sum_k(arr, k):
    cumulative_sum_map = {}
    cumulative_sum = 0
    max_length = 0

    for i in range(len(arr)):
        cumulative_sum += arr[i]

        if cumulative_sum == k:
            max_length = i + 1

        if (cumulative_sum - k) in cumulative_sum_map:
            subarray_length = i - cumulative_sum_map[cumulative_sum - k]
            max_length = max(max_length, subarray_length)

        if cumulative_sum not in cumulative_sum_map:
            cumulative_sum_map[cumulative_sum] = i

    return max_length
