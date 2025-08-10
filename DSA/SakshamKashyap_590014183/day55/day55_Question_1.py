def longest_subarray_with_sum_k(arr, k):
    prefix_sum_indices = {0: -1}  # sum -> first index
    prefix_sum = 0
    max_len = 0

    for i, num in enumerate(arr):
        prefix_sum += num
        if prefix_sum - k in prefix_sum_indices:
            max_len = max(max_len, i - prefix_sum_indices[prefix_sum - k])
        # Store the first occurrence only (to maximize window size)
        if prefix_sum not in prefix_sum_indices:
            prefix_sum_indices[prefix_sum] = i
    return max_len

# Example usage:
# print(longest_subarray_with_sum_k([10,5,2,7,1,9], 15)) # Output: 4
# print(longest_subarray_with_sum_k([1,2,3], 3))         # Output: 2

def length_of_longest_substring(s):
    seen = {}
    left = 0
    max_len = 0
    for right, char in enumerate(s):
        if char in seen and seen[char] >= left:
            left = seen[char] + 1
        seen[char] = right
        max_len = max(max_len, right - left + 1)
    return max_len

# Example usage:
# print(length_of_longest_substring("abcabcbb")) # Output: 3
# print(length_of_longest_substring("bbbbb"))    # Output: 1

def num_subarrays_with_sum(nums, goal):
    from collections import defaultdict
    prefix_count = defaultdict(int)
    prefix_count[0] = 1
    prefix_sum = 0
    result = 0
    for num in nums:
        prefix_sum += num
        result += prefix_count[prefix_sum - goal]
        prefix_count[prefix_sum] += 1
    return result

# Example usage:
# print(num_subarrays_with_sum([1,0,1,0,1], 2)) # Output: 4
# print(num_subarrays_with_sum([0,0,0,0,0], 0)) # Output: 15
