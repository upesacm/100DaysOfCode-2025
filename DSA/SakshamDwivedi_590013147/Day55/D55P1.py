def longest_subarr_sum(arr, k):
    prefix_sum = 0
    prefix_map = {}
    max_len = 0

    for i, num in enumerate(arr):
        prefix_sum += num
        if prefix_sum == k:
            max_len = i + 1
        if (prefix_sum - k) in prefix_map:
            length = i - prefix_map[prefix_sum - k]
            max_len = max(max_len, length)
        if prefix_sum not in prefix_map:
            prefix_map[prefix_sum] = i

    return max_len


#Fixed Input
arr = [10, 5, 2, 7, 1, 9]
k = 15
print(longest_subarr_sum(arr, k))
