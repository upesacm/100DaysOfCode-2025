import heapq

def merge_k_sorted(arrays):
    return list(heapq.merge(*arrays))

print(merge_k_sorted([[1, 3], [2, 4], [5, 6]]))
print(merge_k_sorted([[1, 4, 5], [1, 3, 4], [2, 6]]))
