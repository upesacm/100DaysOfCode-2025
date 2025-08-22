import heapq

def merge_k_sorted(arrays):
    heap = []
    for a in range(len(arrays)):
        if len(arrays[a]) > 0:
            heap.append((arrays[a][0], a, 0))
    heapq.heapify(heap)
    ans = []
    while len(heap) > 0:
        value, arr_index, ele_index = heapq.heappop(heap)
        ans.append(value)
        next_index = ele_index + 1
        if next_index < len(arrays[arr_index]):
            next_value = arrays[arr_index][next_index]
            heapq.heappush(heap, (next_value, arr_index, next_index))
    return ans
