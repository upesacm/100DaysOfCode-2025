class TwoStacks:
    def __init__(self, size):
        self.size = size
        self.arr = [None] * size
        self.top1 = -1
        self.top2 = size

    def push1(self, value):
        if self.top1 + 1 < self.top2:
            self.top1 += 1
            self.arr[self.top1] = value
        else:
            raise Exception("Stack Overflow")

    def push2(self, value):
        if self.top1 < self.top2 - 1:
            self.top2 -= 1
            self.arr[self.top2] = value
        else:
            raise Exception("Stack Overflow")

    def pop1(self):
        if self.top1 >= 0:
            value = self.arr[self.top1]
            self.top1 -= 1
            return value
        else:
            raise Exception("Stack1 Underflow")

    def pop2(self):
        if self.top2 < self.size:
            value = self.arr[self.top2]
            self.top2 += 1
            return value
        else:
            raise Exception("Stack2 Underflow")

    def get_stack1(self):
        return self.arr[:self.top1 + 1]

    def get_stack2(self):
        return self.arr[self.top2:]

ts = TwoStacks(10)
ts.push1(1)
ts.push1(2)
ts.push2(9)
ts.push2(8)
ts.push1(3)
ts.pop2()

print("Stack1:", ts.get_stack1())  
print("Stack2:", ts.get_stack2())
