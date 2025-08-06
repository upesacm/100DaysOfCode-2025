def count_anagram_occurrences(text, pattern):
    from collections import Counter

    k = len(pattern)
    pattern_count = Counter(pattern)
    window_count = Counter(text[:k])
    result = 0

    if window_count == pattern_count:
        result += 1

    for i in range(k, len(text)):
        window_count[text[i]] += 1
        window_count[text[i - k]] -= 1
        if window_count[text[i - k]] == 0:
            del window_count[text[i - k]]
        if window_count == pattern_count:
            result += 1

    return result

# Example usage:
print(count_anagram_occurrences("forxxorfxdofr", "for"))  # Output: 3
print(count_anagram_occurrences("aabaabaa", "aaba"))      # Output: 4
