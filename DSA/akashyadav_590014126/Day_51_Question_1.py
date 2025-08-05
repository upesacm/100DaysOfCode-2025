def longest_k_unique_substring(s, k):
    from collections import defaultdict

    left = 0
    max_len = 0
    char_freq = defaultdict(int)

    for right in range(len(s)):
        char_freq[s[right]] += 1

        while len(char_freq) > k:
            char_freq[s[left]] -= 1
            if char_freq[s[left]] == 0:
                del char_freq[s[left]]
            left += 1

        if len(char_freq) == k:
            max_len = max(max_len, right - left + 1)

    return max_len
