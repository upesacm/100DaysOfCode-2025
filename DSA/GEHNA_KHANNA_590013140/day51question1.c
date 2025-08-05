def longest_substring_with_k_unique_chars(s, k):
    if k == 0 or not s:
        return 0

    start = 0
    max_len = 0
    char_freq = {}

    for end in range(len(s)):
        char = s[end]
        char_freq[char] = char_freq.get(char, 0) + 1

        while len(char_freq) > k:
            start_char = s[start]
            char_freq[start_char] -= 1
            if char_freq[start_char] == 0:
                del char_freq[start_char]
            start += 1

        if len(char_freq) == k:
            max_len = max(max_len, end - start + 1)

    return max_len
