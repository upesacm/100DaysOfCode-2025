class MaxHeap:
    def __init__(self):
        self.heap = []

    def insert(self, val):
        self.heap.append(val)
        self._bubble_up(len(self.heap) - 1)

    def _bubble_up(self, index):
        parent = (index - 1) // 2
        while index > 0 and self.heap[index] > self.heap[parent]:
            self.heap[index], self.heap[parent] = self.heap[parent], self.heap[index]
            index = parent
            parent = (index - 1) // 2

    def delete_root(self):
        if len(self.heap) == 0:
            return None
        root = self.heap[0]
        last = self.heap.pop()
        if self.heap:
            self.heap[0] = last
            self._heapify_down(0)
        return root

    def _heapify_down(self, index):
        largest = index
        left = 2 * index + 1
        right = 2 * index + 2
        if left < len(self.heap) and self.heap[left] > self.heap[largest]:
            largest = left
        if right < len(self.heap) and self.heap[right] > self.heap[largest]:
            largest = right
        if largest != index:
            self.heap[index], self.heap[largest] = self.heap[largest], self.heap[index]
            self._heapify_down(largest)
    def __str__(self):
        return str(self.heap)


# Example 1
h = MaxHeap()
for val in [20, 15, 8]:
    h.insert(val)
h.delete_root()  # delete max
print("Heap after operations:", h)
# Example 2
h = MaxHeap()
for val in [30, 25, 10, 35]:
    h.insert(val)
h.delete_root()
h.insert(40)
print("Heap after operations:", h)