def longestSubarraySumK(arr, k):
    prefix_sum = 0
    mp = {}
    max_len = 0
    for i, num in enumerate(arr):
        prefix_sum += num
        if prefix_sum == k:
            max_len = i + 1
        if prefix_sum - k in mp:
            max_len = max(max_len, i - mp[prefix_sum - k])
        if prefix_sum not in mp:
            mp[prefix_sum] = i
    return max_len

print(longestSubarraySumK([10, 5, 2, 7, 1, 9], 15))
print(longestSubarraySumK([1, 2, 3], 3))
