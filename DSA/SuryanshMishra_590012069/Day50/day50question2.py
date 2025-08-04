# 2. Count Occurrences of Anagram
# A problem that demonstrates pattern matching techniques and teaches anagram detection algorithms using frequency-based sliding window methods for string analysis and pattern recognition operations.

# Given a text and a pattern, return the number of occurrences of the anagram of the pattern in the text using sliding window technique. This operation is fundamental in string pattern matching and anagram analysis where you need to detect character rearrangements within text efficiently. The technique uses frequency-based sliding window to track character counts and identify anagram matches without generating all permutations. This concept is essential in text processing, plagiarism detection, and bioinformatics where finding character pattern variations enables content analysis and sequence matching in large text datasets.

# This introduces anagram detection algorithms and frequency-based pattern matching techniques that are crucial for text analysis and efficient string pattern recognition operations.

# Your task: Implement frequency-based sliding window to detect anagram patterns by tracking character counts and identifying matching distributions.

# Examples
# Input:

# text = "forxxorfxdofr", pattern = "for"
# Output:

# 3
# Input:

# text = "aabaabaa", pattern = "aaba"
# Output:

# 4
from collections import Counter

def count_anagram_occurrences(text: str, pattern: str) -> int:
    len_p = len(pattern)
    len_t = len(text)

    if len_p > len_t:
        return 0

    pattern_count = Counter(pattern)
    window_count = Counter(text[:len_p])
    result = 0

    if window_count == pattern_count:
        result += 1

    for i in range(len_p, len_t):
        start_char = text[i - len_p]
        end_char = text[i]

        window_count[end_char] += 1
        window_count[start_char] -= 1

        if window_count[start_char] == 0:
            del window_count[start_char] 

        if window_count == pattern_count:
            result += 1

    return result
