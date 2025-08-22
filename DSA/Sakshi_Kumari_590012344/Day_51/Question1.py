def longest_substring_k_unique(s, k):
    if not isinstance(s, str) or not isinstance(k, int):
        return 0

    if k <= 0 or s == "":
        return 0

    unique_chars = set(s)
    if k > len(unique_chars):
        return 0

    char_count = {}
    start = 0
    max_length = 0

    for end in range(len(s)):
        current_char = s[end]
        if current_char in char_count:
            char_count[current_char] += 1
        else:
            char_count[current_char] = 1

        while len(char_count) > k:
            left_char = s[start]
            char_count[left_char] -= 1
            if char_count[left_char] == 0:
                del char_count[left_char]
            start += 1

        if len(char_count) == k:
            window_length = end - start + 1
            if window_length > max_length:
                max_length = window_length

    return max_length
