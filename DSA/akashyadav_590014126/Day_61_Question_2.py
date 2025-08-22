class MaxHeap:
    def __init__(self):
        self.heap=[]

    def insert(self,val):
        self.heap.append(val)
        self._bubbleup_(len(self.heap)-1)
    
    def delete_roots(self):
        if not self.heap:
            return None
        root=self.heap[0]
        last=self.heap.pop()
        if self.heap():
            self.heap[0]=last
            self._sift_down[0]
        return root
    
    def _bubble_up(self,index):
        parent=(index-1)//2
        while index>0 and self.heapheap[index] > self.heap[parent]:
            self.heap[index], self.heap[parent] = self.heap[parent], self.heap[index]
            index = parent
            parent = (index - 1) // 2

    def _sift_down(self, index):
        n = len(self.heap)
        while True:
            largest = index
            left = 2 * index + 1
            right = 2 * index + 2

            if left < n and self.heap[left] > self.heap[largest]:
                largest = left
            if right < n and self.heap[right] > self.heap[largest]:
                largest = right

            if largest == index:
                break

            self.heap[index], self.heap[largest] = self.heap[largest], self.heap[index]
            index = largest

    def get_heap(self):
        return self.heap