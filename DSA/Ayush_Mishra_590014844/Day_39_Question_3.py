class TwoStacks:
    def __init__(self, size):
        self.size = size
        self.arr = [None] * size
        self.top1 = -1
        self.top2 = size

    def push1(self, val):
        if self.top1 + 1 == self.top2:
            return
        self.top1 += 1
        self.arr[self.top1] = val

    def push2(self, val):
        if self.top2 - 1 == self.top1:
            return
        self.top2 -= 1
        self.arr[self.top2] = val

    def pop1(self):
        if self.top1 == -1:
            return None
        val = self.arr[self.top1]
        self.top1 -= 1
        return val

    def pop2(self):
        if self.top2 == self.size:
            return None
        val = self.arr[self.top2]
        self.top2 += 1
        return val

    def print1(self):
        print(*self.arr[:self.top1 + 1])

    def print2(self):
        print(*self.arr[self.top2:][::-1])

s = TwoStacks(100)
s.push1(1)
s.push1(2)
s.push2(9)
s.push2(8)
s.print1()
s.print2()
s.push1(3)
s.pop2()
s.print1()
s.print2()
