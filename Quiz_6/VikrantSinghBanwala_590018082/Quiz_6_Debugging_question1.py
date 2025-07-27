'''1.line having bug is 
if val == self.min_stack[-1]:
and 
if val < self.min_val:
    self.min_val = val
2.causes incorrect behavior because when minimum element is popped, self.min_val remains unchanged,
 leading to incorrect results from get_min(), as it still returns the old minimum instead of new one.
 
 correct code:'''
class MinStack:
    def __init__(self):
        self.stack = []
        self.min_stack = []

    def push(self, val):
        self.stack.append(val)
        if not self.min_stack or val <= self.min_stack[-1]:
            self.min_stack.append(val)

    def pop(self):
        if not self.stack:
            return None
        val = self.stack.pop()
        if val == self.min_stack[-1]:
            self.min_stack.pop()
        return val

    def get_min(self):
        return self.min_stack[-1] if self.min_stack else None


min_stack = MinStack()
min_stack.push(5)
min_stack.push(2)
min_stack.push(8)
print(min_stack.get_min())
min_stack.pop()
min_stack.pop()
print(min_stack.get_min())
