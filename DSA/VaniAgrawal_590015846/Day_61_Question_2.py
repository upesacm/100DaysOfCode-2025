#Implement complete heap manipulation with proper insertion using bubble-up and deletion using extract-root with sift-down restoration.
def heapify_max(arr, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2
    if left < n and arr[left] > arr[largest]:
        largest = left
    if right < n and arr[right] > arr[largest]:
        largest = right
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify_max(arr, n, largest)

def insert_max_heap(heap, value):
    heap.append(value)
    i = len(heap) - 1
    while i > 0:
        parent = (i - 1) // 2
        if heap[i] > heap[parent]:
            heap[i], heap[parent] = heap[parent], heap[i]
            i = parent
        else:
            break

def delete_root(heap):
    if len(heap) == 0:
        return
    heap[0] = heap[-1]
    heap.pop()
    heapify_max(heap, len(heap), 0)

heap = []
insert_values = list(map(int, input("Enter elements to insert (space-separated): ").split()))
for v in insert_values:
    insert_max_heap(heap, v)

delete_choice = input("Delete root? (y/n): ").strip().lower()
if delete_choice == "y":
    delete_root(heap)

print("Heap after operations:", heap)
