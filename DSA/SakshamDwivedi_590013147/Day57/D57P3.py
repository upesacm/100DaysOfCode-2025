import heapq

def merge_k_srtd_arrs(arrays):
    heap = []
    result = []
    for i, arr in enumerate(arrays):
        if arr:
            heapq.heappush(heap, (arr[0], i, 0))

    while heap:
        val, arr_idx, elem_idx = heapq.heappop(heap)
        result.append(val)
        if elem_idx + 1 < len(arrays[arr_idx]):
            heapq.heappush(heap, (arrays[arr_idx][elem_idx + 1], arr_idx, elem_idx + 1))

    return result

#Fixed Input
arrays = [[1, 3], [2, 4], [5, 6]]
print(merge_k_srtd_arrs(arrays))
