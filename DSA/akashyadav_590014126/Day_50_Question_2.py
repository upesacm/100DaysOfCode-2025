from collections import Counter

def count_anagrams(text, pattern):
    k = len(pattern)
    pattern_count = Counter(pattern)
    window_count = Counter()
    count = 0

    for i in range(len(text)):
        window_count[text[i]] += 1

        if i >= k:
            if window_count[text[i - k]] == 1:
                del window_count[text[i - k]]
            else:
                window_count[text[i - k]] -= 1

        if window_count == pattern_count:
            count += 1

    return count

# Example usage
print(count_anagrams("ccdcdccdc", "ccdc"))