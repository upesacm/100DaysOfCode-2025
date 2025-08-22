def longest_substring_k_unique(s, k):
    from collections import defaultdict

    if k == 0:
        return 0

    char_freq = defaultdict(int)
    start = 0
    max_length = 0
    unique_count = 0

    for end in range(len(s)):
        if char_freq[s[end]] == 0:
            unique_count += 1
        char_freq[s[end]] += 1

        while unique_count > k:
            char_freq[s[start]] -= 1
            if char_freq[s[start]] == 0:
                unique_count -= 1
            start += 1

        if unique_count == k:
            max_length = max(max_length, end - start + 1)

    return max_length

# Example usage:
print(longest_substring_k_unique("aabacbebebe", 3))  # Output: 7
print(longest_substring_k_unique("aaaa", 2))         # Output: 0
