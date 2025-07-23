class MinStack:
    def __init__(self):
        self.stack = []
        self.min_stack = []
    def push(self, val):
        self.stack.append(val)
        if not self.min_stack or val <= self.min_stack[-1]:
            self.min_stack.append(val)
    def get_min(self):
        if self.min_stack:
            print(self.min_stack[-1])
s = MinStack()
arr = list(map(int, input().split()))
for val in arr:
    s.push(val)
s.get_min()
#fro example :
# input:- 5 3 7
# output:- 3
