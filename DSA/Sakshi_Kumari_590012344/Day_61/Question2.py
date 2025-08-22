def insert_max_heap(heap, value):
    heap.append(value)
    index = len(heap) - 1
    while index > 0:
        parent = (index - 1) // 2
        if heap[index] > heap[parent]:
            heap[index], heap[parent] = heap[parent], heap[index]
            index = parent
        else:
            break

def delete_max_heap(heap):
    if len(heap) == 0:
        return None
    root = heap[0]
    heap[0] = heap[-1]
    heap.pop()
    index = 0
    while True:
        left = 2 * index + 1
        right = 2 * index + 2
        largest = index
        if left < len(heap) and heap[left] > heap[largest]:
            largest = left
        if right < len(heap) and heap[right] > heap[largest]:
            largest = right
        if largest != index:
            heap[index], heap[largest] = heap[largest], heap[index]
            index = largest
        else:
            break
    return root
