import heapq
from collections import Counter

def top_k_frequent(arr, k):
    freq = Counter(arr)
    return [item for item, _ in heapq.nlargest(k, freq.items(), key=lambda x: x[1])]

print(top_k_frequent([1, 1, 1, 2, 2, 3], 2))
print(top_k_frequent([4, 1, -1, 2, -1, 2, 3], 2))
