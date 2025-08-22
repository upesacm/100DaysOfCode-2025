class MinHeap:
    def __init__(self):
        self.h = []

    def insert(self, x):
        self.h.append(x)
        i = len(self.h) - 1
        while i > 0 and self.h[i] < self.h[(i-1)//2]:
            self.h[i], self.h[(i-1)//2] = self.h[(i-1)//2], self.h[i]
            i = (i-1)//2

    def extractMin(self):
        if not self.h: return None
        if len(self.h) == 1: return self.h.pop()
        root = self.h[0]
        self.h[0] = self.h.pop()
        i = 0
        while True:
            l, r = 2*i+1, 2*i+2
            s = i
            if l < len(self.h) and self.h[l] < self.h[s]: s = l
            if r < len(self.h) and self.h[r] < self.h[s]: s = r
            if s != i:
                self.h[i], self.h[s] = self.h[s], self.h[i]
                i = s
            else: break
        return root


#Fixed Input
heap = MinHeap()
for i in [3, 2, 15]: heap.insert(i)
print(heap.extractMin())
