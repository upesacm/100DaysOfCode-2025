class MaxHeap:
    def __init__(self):
        self.heap = []

    def insert(self, val):
        self.heap.append(val)
        self._bubbleUp(len(self.heap) - 1)

    def _bubbleUp(self, index):
        parent = (index - 1) // 2
        while index > 0 and self.heap[parent] < self.heap[index]:
            self.heap[parent], self.heap[index] = self.heap[index], self.heap[parent]
            index = parent
            parent = (index - 1) // 2

    def deleteRoot(self):
        if len(self.heap) == 0:
            return None
        if len(self.heap) == 1:
            return self.heap.pop()

        root_val = self.heap[0]
        self.heap = self.heap.pop()
        self._siftDown(0)
        return root_val

    def _siftDown(self, index):
        largest = index
        left = 2 * index + 1
        right = 2 * index + 2

        if left < len(self.heap) and self.heap[left] > self.heap[largest]:
            largest = left
        if right < len(self.heap) and self.heap[right] > self.heap[largest]:
            largest = right

        if largest != index:
            self.heap[index], self.heap[largest] = self.heap[largest], self.heap[index]
            self._siftDown(largest)

# Example Usage
h = MaxHeap()
h.insert(20)
h.insert(15)
h.insert(8)
print("Heap after inserts:", h.heap)
h.deleteRoot()
print("Heap after deleting root:", h.heap)

h2 = MaxHeap()
for val in [30, 25, 10, 35]:
    h2.insert(val)
h2.deleteRoot()
h2.insert(40)
print("Heap after operations:", h2.heap)
