import heapq

def merge_k_sorted_array(arrays):
    min_heap=[]
    result=[]

    for i,arr in enumerate(arrays):
        if arr:
            heapq.heappush(min_heap, (arr[0],i,0))

    while min_heap:
        val,arr_idx,elem_idx=heapq.heappop(min_heap)
        result.append(val)

        if elem_idx + 1 < len(arrays[arr_idx]):
            next_val=arrays[arr_idx][elem_idx + 1]
            heapq.heappush(min_heap, (next_val, arr_idx, elem_idx+1))

    return result

#example
print(merge_k_sorted_array([[3,6],[1,2],[7,8]]))
