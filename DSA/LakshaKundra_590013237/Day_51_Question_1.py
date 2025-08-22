def longest_k_unique_substring(s, k):
    n = len(s)
    if n == 0 or k == 0:
        return 0

    left = 0
    max_len = 0
    freq = {}

    for right in range(n):
        freq[s[right]] = freq.get(s[right], 0) + 1

        while len(freq) > k:
            freq[s[left]] -= 1
            if freq[s[left]] == 0:
                del freq[s[left]]
            left += 1

        if len(freq) == k:
            max_len = max(max_len, right - left + 1)

    return max_len

print(longest_k_unique_substring("aabacbebebe", 3))  # Output: 7
print(longest_k_unique_substring("aaaa", 2))         # Output: 0
