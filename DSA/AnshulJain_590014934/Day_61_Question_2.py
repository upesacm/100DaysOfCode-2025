def heapify_down(heap, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2
    if left < n and heap[left] > heap[largest]:
        largest = left
    if right < n and heap[right] > heap[largest]:
        largest = right
    if largest != i:
        heap[i], heap[largest] = heap[largest], heap[i]
        heapify_down(heap, n, largest)

def heapify_up(heap, i):
    while i > 0:
        parent = (i - 1) // 2
        if heap[i] > heap[parent]:
            heap[i], heap[parent] = heap[parent], heap[i]
            i = parent
        else:
            break

def insert(heap, val):
    heap.append(val)
    heapify_up(heap, len(heap) - 1)

def delete_root(heap):
    if len(heap) == 0:
        return
    heap[0] = heap[-1]
    heap.pop()
    heapify_down(heap, len(heap), 0)
heap = []
ops = input().split(',')
for op in ops:
    op = op.strip()
    if op.lower().startswith("insert"):
        val = int(op.split()[1])
        insert(heap, val)
    elif op.lower().startswith("delete"):
        delete_root(heap)
print(heap)
