import heapq

def k_largest(arr, k):
    return heapq.nlargest(k, arr)

print(k_largest([1, 23, 12, 9, 30, 2, 50], 3))
print(k_largest([10, 15, 5], 2))
