def longest_subarray_with_sum_k(arr, k):
    prefix_sum_map = {}  
    curr_sum = 0
    max_len = 0

    for i, num in enumerate(arr):
        curr_sum += num

        if curr_sum == k:
            max_len = i + 1

        if (curr_sum - k) in prefix_sum_map:
            max_len = max(max_len, i - prefix_sum_map[curr_sum - k])

        if curr_sum not in prefix_sum_map:
            prefix_sum_map[curr_sum] = i

    return max_len
