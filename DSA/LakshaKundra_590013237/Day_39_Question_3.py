class TwoStacks:
    def __init__(self, size):
        self.arr = [None] * size
        self.top1 = -1
        self.top2 = size
        self.size = size

    def push1(self, value):
        if self.top1 + 1 < self.top2:
            self.top1 += 1
            self.arr[self.top1] = value

    def push2(self, value):
        if self.top1 + 1 < self.top2:
            self.top2 -= 1
            self.arr[self.top2] = value

    def pop1(self):
        if self.top1 >= 0:
            val = self.arr[self.top1]
            self.top1 -= 1
            return val

    def pop2(self):
        if self.top2 < self.size:
            val = self.arr[self.top2]
            self.top2 += 1
            return val

    def get_stack1(self):
        return self.arr[:self.top1 + 1]

    def get_stack2(self):
        return self.arr[self.top2:]

s = TwoStacks(10)
s.push1(1)
s.push1(2)
s.push2(9)
s.push2(8)
print("Stack1:", s.get_stack1())
print("Stack2:", s.get_stack2())

s.push1(3)
s.pop2()
print("Stack1:", s.get_stack1())
print("Stack2:", s.get_stack2())
