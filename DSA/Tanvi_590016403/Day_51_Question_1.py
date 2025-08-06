from collections import defaultdict

# 1. Longest Substring with K Unique Characters
def longest_substring_with_k_unique_chars(s: str, k: int) -> int:
    if k == 0 or not s:
        return 0

    left = 0
    max_len = 0
    freq = defaultdict(int)

    for right in range(len(s)):
        freq[s[right]] += 1

        while len(freq) > k:
            freq[s[left]] -= 1
            if freq[s[left]] == 0:
                del freq[s[left]]
            left += 1

        if len(freq) == k:
            max_len = max(max_len, right - left + 1)

    return max_len


# 2. Smallest Subarray with Sum Greater than X
def smallest_subarray_with_sum_greater_than_x(arr, x):
    n = len(arr)
    min_len = float('inf')
    current_sum = 0
    start = 0

    for end in range(n):
        current_sum += arr[end]

        while current_sum > x:
            min_len = min(min_len, end - start + 1)
            current_sum -= arr[start]
            start += 1

    return 0 if min_len == float('inf') else min_len


# 3. Minimum Window Substring
def min_window_substring(s: str, t: str) -> str:
    if not s or not t:
        return ""

    dict_t = defaultdict(int)
    for char in t:
        dict_t[char] += 1

    required = len(dict_t)
    l, r = 0, 0
    formed = 0
    window_counts = defaultdict(int)
    ans = float('inf'), None, None

    while r < len(s):
        window_counts[s[r]] += 1

        if s[r] in dict_t and window_counts[s[r]] == dict_t[s[r]]:
            formed += 1

        while l <= r and formed == required:
            if r - l + 1 < ans[0]:
                ans = (r - l + 1, l, r)

            window_counts[s[l]] -= 1
            if s[l] in dict_t and window_counts[s[l]] < dict_t[s[l]]:
                formed -= 1
            l += 1

        r += 1

    return "" if ans[0] == float('inf') else s[ans[1]:ans[2] + 1]


# -----------------------------
# Example Test Cases:
if __name__ == "__main__":
    # Problem 1
    print("Longest Substring with K Unique Characters:")
    print(longest_substring_with_k_unique_chars("aabacbebebe", 3))  # Output: 7
    print(longest_substring_with_k_unique_chars("aaaa", 2))         # Output: 0

    # Problem 2
    print("\nSmallest Subarray with Sum Greater than X:")
    print(smallest_subarray_with_sum_greater_than_x([1, 4, 45, 6, 0, 19], 51))  # Output: 3
    print(smallest_subarray_with_sum_greater_than_x([1, 10, 5, 2, 7], 9))       # Output: 1

    # Problem 3
    print("\nMinimum Window Substring:")
    print(min_window_substring("ADOBECODEBANC", "ABC"))  # Output: "BANC"
    print(min_window_substring("a", "a"))                # Output: "a"
