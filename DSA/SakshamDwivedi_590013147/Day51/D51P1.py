def longest_k_unique_substring(s, k):
    n = len(s)
    if n == 0 or k == 0:
        return 0

    freq = {}
    left = 0
    max_len = 0

    for right in range(n):
        if s[right] in freq:
            freq[s[right]] += 1
        else:
            freq[s[right]] = 1

        while len(freq) > k:
            freq[s[left]] -= 1
            if freq[s[left]] == 0:
                del freq[s[left]]
            left += 1
          
        if len(freq) == k:
            max_len = max(max_len, right - left + 1)

    return max_len

#Fixed Input
print(longest_k_unique_substring("aabacbebebe", 3))
