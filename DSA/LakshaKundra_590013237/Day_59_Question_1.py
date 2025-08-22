class MinHeap:
    def __init__(self):
        self.heap = []
    def insert(self, val):
        self.heap.append(val)
        i = len(self.heap) - 1
        while i > 0 and self.heap[(i - 1) // 2] > self.heap[i]:
            self.heap[i], self.heap[(i - 1) // 2] = self.heap[(i - 1) // 2], self.heap[i]
            i = (i - 1) // 2
    def extractMin(self):
        if not self.heap:
            return None
        if len(self.heap) == 1:
            return self.heap.pop()
        root = self.heap[0]
        self.heap[0] = self.heap.pop()
        self._heapify(0)
        return root
    def _heapify(self, i):
        l, r, smallest = 2*i + 1, 2*i + 2, i
        if l < len(self.heap) and self.heap[l] < self.heap[smallest]:
            smallest = l
        if r < len(self.heap) and self.heap[r] < self.heap[smallest]:
            smallest = r
        if smallest != i:
            self.heap[i], self.heap[smallest] = self.heap[smallest], self.heap[i]
            self._heapify(smallest)

h = MinHeap()
h.insert(3)
h.insert(2)
h.insert(15)
print(h.extractMin())

h = MinHeap()
for x in [10, 5, 20, 8]:
    h.insert(x)
print(h.extractMin())
print(h.extractMin())
