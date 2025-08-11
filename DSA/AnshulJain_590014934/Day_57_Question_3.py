import heapq
import ast
arrays = ast.literal_eval(input("Enter the arrays: "))
heap = []
for i, arr in enumerate(arrays):
    if arr:
        heapq.heappush(heap, (arr[0], i, 0))
result = []
while heap:
    val, r, c = heapq.heappop(heap)
    result.append(val)
    if c + 1 < len(arrays[r]):
        heapq.heappush(heap, (arrays[r][c+1], r, c+1))
print(result)
#for eample:
#input: arr=[1, 4, 5], [1, 3, 4], [2, 6]
#output: [1, 1, 2, 3, 4, 4, 5, 6]
