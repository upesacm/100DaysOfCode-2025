class MinHeap:
    def __init__(self):
        self.heap = []

    def insert(self, val):
        # Add at end and bubble-up
        self.heap.append(val)
        self._bubble_up(len(self.heap) - 1)

    def extractMin(self):
        if not self.heap:
            return None
        if len(self.heap) == 1:
            return self.heap.pop()

        # Swap first and last
        root = self.heap[0]
        self.heap[0] = self.heap.pop()
        self._bubble_down(0)
        return root

    def _bubble_up(self, index):
        parent = (index - 1) // 2
        while index > 0 and self.heap[index] < self.heap[parent]:
            self.heap[index], self.heap[parent] = self.heap[parent], self.heap[index]
            index = parent
            parent = (index - 1) // 2

    def _bubble_down(self, index):
        smallest = index
        left = 2 * index + 1
        right = 2 * index + 2

        if left < len(self.heap) and self.heap[left] < self.heap[smallest]:
            smallest = left
        if right < len(self.heap) and self.heap[right] < self.heap[smallest]:
            smallest = right

        if smallest != index:
            self.heap[index], self.heap[smallest] = self.heap[smallest], self.heap[index]
            self._bubble_down(smallest)


# Example usage
min_heap = MinHeap()
for val in [3, 2, 15]:
    min_heap.insert(val)
print(min_heap.extractMin())  # Output: 2
