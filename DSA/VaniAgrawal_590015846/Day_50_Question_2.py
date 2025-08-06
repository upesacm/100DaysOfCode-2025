# Implement frequency-based sliding window to detect anagram patterns by tracking character counts and identifying matching distributions.
from collections import Counter

text = input("Enter the text: ")
pattern = input("Enter the pattern: ")

k = len(pattern)
pattern_count = Counter(pattern)
window_count = Counter(text[:k-1])

result = 0

for i in range(k-1, len(text)):
    window_count[text[i]] += 1
    if window_count == pattern_count:
        result += 1

    window_count[text[i - k + 1]] -= 1
    if window_count[text[i - k + 1]] == 0:
        del window_count[text[i - k + 1]]

print("Number of anagram occurrences:", result)
