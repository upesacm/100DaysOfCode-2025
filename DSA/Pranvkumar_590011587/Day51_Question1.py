def longest_substring_k_unique(s, k):
    from collections import defaultdict
    n = len(s)
    left = 0
    max_len = 0
    freq = defaultdict(int)
    for right in range(n):
        freq[s[right]] += 1
        while len(freq) > k:
            freq[s[left]] -= 1
            if freq[s[left]] == 0:
                del freq[s[left]]
            left += 1
        if len(freq) == k:
            max_len = max(max_len, right - left + 1)
    return max_len

s = "aabacbebebe"
k = 3
result = longest_substring_k_unique(s, k)
print(result)  