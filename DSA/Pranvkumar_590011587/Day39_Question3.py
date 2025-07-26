class TwoStacks:
    def __init__(self, size):
        self.size = size
        self.arr = [None] * size
        self.top1 = -1
        self.top2 = size
    def push1(self, x):
        if self.top1 < self.top2 - 1:
            self.top1 += 1
            self.arr[self.top1] = x
        else:
            print("Stack Overflow in Stack1")
    def push2(self, x):
        if self.top1 < self.top2 - 1:
            self.top2 -= 1
            self.arr[self.top2] = x
        else:
            print("Stack Overflow in Stack2")
    def pop1(self):
        if self.top1 >= 0:
            val = self.arr[self.top1]
            self.top1 -= 1
            return val
        else:
            print("Stack Underflow in Stack1")
    def pop2(self):
        if self.top2 < self.size:
            val = self.arr[self.top2]
            self.top2 += 1
            return val
        else:
            print("Stack Underflow in Stack2")
    def get_stack1(self):
        return self.arr[:self.top1+1]
    def get_stack2(self):
        return self.arr[self.top2:]
    
# Example Usage
ts = TwoStacks(10)
ts.push1(1)
ts.push1(2)
ts.push2(9)
ts.push2(8)
print("Stack1:", ts.get_stack1())  
print("Stack2:", ts.get_stack2()) 

ts.push1(3)
ts.pop2()
print("Stack1:", ts.get_stack1())  
print("Stack2:", ts.get_stack2())  