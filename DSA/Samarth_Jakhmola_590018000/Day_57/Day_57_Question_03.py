import heapq

def merge_sorted_arrays(arrays):
    min_heap = []
    result = []

    # Step 1 : Push the first element of each array into the heap
    for i, arr in enumerate(arrays):
        if arr:  # Avoids empty arrays
            heapq.heappush(min_heap, (arr[0], i, 0))

    # Step 2 : Extract minimum, push the next element from same array
    while min_heap:
        val, arr_idx, ele_idx = heapq.heappop(min_heap)
        result.append(val)

        # If the array has more elements, push next element into heap
        if ele_idx + 1 < len(arrays[arr_idx]):
            next_val = arrays[arr_idx][ele_idx + 1]
            heapq.heappush(min_heap, (next_val, arr_idx, ele_idx + 1))

    return result


k = int(input("Enter the number of arrays you want to enter : "))
arrays = []
for i in range(1, k + 1):
    array = list(map(int, input(f"Enter the {i} array : ").split()))
    arrays.append(array)

print(merge_sorted_arrays(arrays))
