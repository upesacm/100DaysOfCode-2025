from collections import Counter

def count_anagram_occurrences(text, pattern):
    pattern_length = len(pattern)
    pattern_count = Counter(pattern)
    window_count = Counter(text[:pattern_length])

    count = 0
    if window_count == pattern_count:
        count += 1

    for i in range(pattern_length, len(text)):
        new_char = text[i]
        old_char = text[i - pattern_length]

        window_count[new_char] += 1
        window_count[old_char] -= 1

        if window_count[old_char] == 0:
            del window_count[old_char]

        if window_count == pattern_count:
            count += 1

    return count

