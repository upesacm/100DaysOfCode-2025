from collections import Counter

def count_occurrences(queue):
    return dict(Counter(queue))

print(count_occurrences([1, 2, 2, 3, 1, 1]))
print(count_occurrences([5, 5, 7, 8, 7]))
