class TwoStacks:
    def __init__(self, n):
        self.a = [None]*n
        self.t1, self.t2 = -1, n
    def push1(self, x):
        if self.t1+1 != self.t2:
            self.t1 += 1
            self.a[self.t1] = x
    def push2(self, x):
        if self.t2-1 != self.t1:
            self.t2 -= 1
            self.a[self.t2] = x
    def get1(self):
        return self.a[:self.t1+1]
    def get2(self):
        return self.a[self.t2:]
n = int(input("Enter the size of stacks: "))# Taking input from the user 
ts = TwoStacks(n)
for _ in range(int(input("Enter number of operations: "))):
    c = input().split()
    if c[0]=='push1': ts.push1(int(c[1]))
    elif c[0]=='push2': ts.push2(int(c[1]))
print("Stack1:", ts.get1())
print("Stack2:", ts.get2())
#for example:
# Input: 5
# Operations: push1 10, push2 20, push1 30
# Output: Stack1: [10, 30], Stack2: [20]