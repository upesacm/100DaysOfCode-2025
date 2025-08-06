def min_window_substring(s, t):
    if not s or not t or len(t) > len(s):
        return ""

    from collections import Counter

    required_chars = Counter(t)
    window_counts = {}
    required_unique = len(required_chars)
    formed = 0

    left = 0
    min_len = float("inf")
    min_start = 0

    for right in range(len(s)):
        char = s[right]
        window_counts[char] = window_counts.get(char, 0) + 1

        if char in required_chars and window_counts[char] == required_chars[char]:
            formed += 1

        while formed == required_unique:
            window_size = right - left + 1
            if window_size < min_len:
                min_len = window_size
                min_start = left

            left_char = s[left]
            window_counts[left_char] -= 1
            if left_char in required_chars and window_counts[left_char] < required_chars[left_char]:
                formed -= 1

            left += 1

    if min_len == float("inf"):
        return ""
    return s[min_start:min_start + min_len]
