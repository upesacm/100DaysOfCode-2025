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
            print("Stack Overflow in Stack1")

    def push2(self, value):
        if self.top1 + 1 < self.top2:
            self.top2 -= 1
            self.arr[self.top2] = value
        else:
            print("Stack Overflow in Stack2")

    def pop1(self):
        if self.top1 >= 0:
            val = self.arr[self.top1]
            self.top1 -= 1
            return val
        else:
            print("Stack1 is Empty")

    def pop2(self):
        if self.top2 < self.size:
            val = self.arr[self.top2]
            self.top2 += 1
            return val
        else:
            print("Stack2 is Empty")

    def get_stack1(self):
        return self.arr[:self.top1 + 1]

    def get_stack2(self):
        return self.arr[self.top2:]
