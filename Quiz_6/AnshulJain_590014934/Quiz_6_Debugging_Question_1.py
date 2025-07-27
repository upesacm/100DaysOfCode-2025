class MinStack:
    def __init__(self):
        self.stack = []
        self.min_val = float("inf")

    def push(self, val):
        self.stack.append(val)
        if val < self.min_val:
            self.min_val = val

    def pop(self):
        if self.stack:
            popped = self.stack.pop()
            return popped

    def get_min(self):
        return self.min_val
min_stack = MinStack()
min_stack.push(5)
min_stack.push(2)
min_stack.push(8)
print(min_stack.get_min())#should print 2
min_stack.pop()
min_stack.pop()  #popping the minimum element(2)
print(min_stack.get_min())  
# Task Answer:
# 1. Line(s) causing the bug:
# - Line in push: if val < self.min_val: self.min_val = val
# - pop() method: it does not update self.min_val after popping
# 2. Why this causes incorrect behavior:
# When the minimum value (2) is popped, min_val is not recalculated from the remaining elements.
# The min_val remains as 2, even though it is no longer in the stack.
# This leads to get_min() returning an incorrect (outdated) minimum value.
