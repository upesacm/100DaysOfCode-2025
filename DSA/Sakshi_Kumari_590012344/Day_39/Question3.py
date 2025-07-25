class DualStack:
    def __init__(self, size):
        self.array = [None] * size
        self.top1 = -1
        self.top2 = size
        self.size = size

    def push1(self, value):
        if self.top1 + 1 < self.top2:
            self.top1 += 1
            self.array[self.top1] = value

    def push2(self, value):
        if self.top2 - 1 > self.top1:
            self.top2 -= 1
            self.array[self.top2] = value

    def pop1(self):
        if self.top1 >= 0:
            value = self.array[self.top1]
            self.top1 -= 1
            return value

    def pop2(self):
        if self.top2 < self.size:
            value = self.array[self.top2]
            self.top2 += 1
            return value
