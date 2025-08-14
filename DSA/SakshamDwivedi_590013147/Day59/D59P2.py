class MaxHeap:
    def __init__(self):
        self.h = []

    def insert(self, x):
        self.h.append(x)
        i = len(self.h) - 1
        while i > 0 and self.h[i] > self.h[(i-1)//2]:
            self.h[i], self.h[(i-1)//2] = self.h[(i-1)//2], self.h[i]
            i = (i-1)//2

    def extractMax(self):
        if not self.h: return None
        if len(self.h) == 1: return self.h.pop()
        root = self.h[0]
        self.h[0] = self.h.pop()
        i = 0
        while True:
            l, r = 2*i+1, 2*i+2
            m = i
            if l < len(self.h) and self.h[l] > self.h[m]: m = l
            if r < len(self.h) and self.h[r] > self.h[m]: m = r
            if m != i:
                self.h[i], self.h[m] = self.h[m], self.h[i]
                i = m
            else: break
        return root


#Fixed Input
heap = MaxHeap()
for i in [5, 1, 10]: heap.insert(i)
print(heap.extractMax())
