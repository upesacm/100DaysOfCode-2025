def longest_subarray_sum_k(arr, k):
    prefix_sum_indices = {}
    curr_sum = 0
    max_len = 0
    for i, num in enumerate(arr):
        curr_sum += num
        if curr_sum == k:
            max_len = max(max_len, i + 1)
        if (curr_sum - k) in prefix_sum_indices:
            max_len = max(max_len, i - prefix_sum_indices[curr_sum - k])
        if curr_sum not in prefix_sum_indices:
            prefix_sum_indices[curr_sum] = i
    return max_len

# Example
print(longest_subarray_sum_k([10, 5, 2, 7, 1, 9], 15))  
print(longest_subarray_sum_k([1, 2, 3], 3))  