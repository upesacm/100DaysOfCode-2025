def count_anagrams(text, pattern):
    from collections import Counter
    k = len(pattern)
    pattern_count = Counter(pattern)
    window_count = Counter(text[:k])
    count = 0
    if window_count == pattern_count:
        count += 1
    for i in range(k, len(text)):
        window_count[text[i]] += 1
        window_count[text[i - k]] -= 1
        if window_count[text[i - k]] == 0:
            del window_count[text[i - k]]
        if window_count == pattern_count:
            count += 1
    return count

# Example usage:
print(count_anagrams("forxxorfxdofr", "for")) 
print(count_anagrams("aabaabaa", "aaba"))     