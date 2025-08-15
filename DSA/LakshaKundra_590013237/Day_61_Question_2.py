def heap_insert(heap, val):
    heap.append(val)
    i = len(heap) - 1
    while i > 0:
        parent = (i - 1) // 2
        if heap[i] > heap[parent]:
            heap[i], heap[parent] = heap[parent], heap[i]
            i = parent
        else:
            break

def heap_delete_root(heap):
    if len(heap) == 0:
        return
    heap[0] = heap[-1]
    heap.pop()
    i = 0
    while True:
        left, right, largest = 2*i + 1, 2*i + 2, i
        if left < len(heap) and heap[left] > heap[largest]:
            largest = left
        if right < len(heap) and heap[right] > heap[largest]:
            largest = right
        if largest != i:
            heap[i], heap[largest] = heap[largest], heap[i]
            i = largest
        else:
            break

heap = []
heap_insert(heap, 20)
heap_insert(heap, 15)
heap_insert(heap, 8)
heap_delete_root(heap)
print(heap)

heap = []
heap_insert(heap, 30)
heap_insert(heap, 25)
heap_insert(heap, 10)
heap_insert(heap, 35)
heap_delete_root(heap)
heap_insert(heap, 40)
print(heap)
