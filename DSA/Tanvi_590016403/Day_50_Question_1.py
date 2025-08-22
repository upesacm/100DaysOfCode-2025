from collections import defaultdict

# 1. Maximum Sum Subarray of Size K
def max_sum_subarray(arr, k):
    n = len(arr)
    if n < k:
        return "Invalid"
    
    window_sum = sum(arr[:k])
    max_sum = window_sum
    
    for i in range(k, n):
        window_sum += arr[i] - arr[i - k]
        max_sum = max(max_sum, window_sum)
    
    return max_sum

# 2. Count Occurrences of Anagram
def count_anagrams(text, pattern):
    k = len(pattern)
    pattern_freq = defaultdict(int)
    window_freq = defaultdict(int)

    for ch in pattern:
        pattern_freq[ch] += 1

    count = 0
    for i in range(len(text)):
        window_freq[text[i]] += 1

        if i >= k:
            left_char = text[i - k]
            window_freq[left_char] -= 1
            if window_freq[left_char] == 0:
                del window_freq[left_char]
        
        if window_freq == pattern_freq:
            count += 1
    
    return count

# 3. Subarray with Given Sum
def subarray_with_given_sum(arr, target):
    start = 0
    current_sum = 0
    
    for end in range(len(arr)):
        current_sum += arr[end]
        
        while current_sum > target and start < end:
            current_sum -= arr[start]
            start += 1
        
        if current_sum == target:
            return f"Subarray found from index {start} to {end}"
    
    return "No subarray with given sum found"

# ----------- Test Cases -----------

# Test 1
print("1. Maximum Sum Subarray of Size K:")
print(max_sum_subarray([1, 4, 2, 10], 2))          # Output: 12
print(max_sum_subarray([100, 200, 300, 400], 2))   # Output: 700

# Test 2
print("\n2. Count Occurrences of Anagram:")
print(count_anagrams("forxxorfxdofr", "for"))      # Output: 3
print(count_anagrams("aabaabaa", "aaba"))          # Output: 4

# Test 3
print("\n3. Subarray with Given Sum:")
print(subarray_with_given_sum([1, 4, 20, 3, 10, 5], 33))       # Output: index 2 to 4
print(subarray_with_given_sum([1, 4, 0, 0, 3, 10, 5], 7))      # Output: index 1 to 4
