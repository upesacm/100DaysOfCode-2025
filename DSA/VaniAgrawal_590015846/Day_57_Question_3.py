import heapq

# Merge K Sorted Arrays
k = int(input("Enter number of sorted arrays: "))
arrays = []
for i in range(k):
    arr = list(map(int, input(f"Enter elements of array {i+1} separated by space: ").split()))
    arrays.append(arr)

min_heap = []
for i in range(len(arrays)):
    if arrays[i]:  # avoid empty arrays
        heapq.heappush(min_heap, (arrays[i][0], i, 0))

result = []
while min_heap:
    val, list_idx, elem_idx = heapq.heappop(min_heap)
    result.append(val)
    if elem_idx + 1 < len(arrays[list_idx]):
        next_val = arrays[list_idx][elem_idx + 1]
        heapq.heappush(min_heap, (next_val, list_idx, elem_idx + 1))

print("Merged sorted array:", result)
