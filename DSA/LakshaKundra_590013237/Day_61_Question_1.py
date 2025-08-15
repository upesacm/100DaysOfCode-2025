def min_to_max_heap(arr):
    n = len(arr)
    def heapify(i):
        l, r, largest = 2*i+1, 2*i+2, i
        if l < n and arr[l] > arr[largest]:
            largest = l
        if r < n and arr[r] > arr[largest]:
            largest = r
        if largest != i:
            arr[i], arr[largest] = arr[largest], arr[i]
            heapify(largest)
    for i in range(n//2 - 1, -1, -1):
        heapify(i)
    return arr

print(min_to_max_heap([1, 3, 5, 7, 9, 2]))
print(min_to_max_heap([2, 4, 6, 8, 10, 12]))
