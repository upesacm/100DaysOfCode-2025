class q1:
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
#1. Identify the specific line(s) causing the bug:
#def pop(self):
 #   if self.stack:
 #       popped = self.stack.pop()
 #       return popped
#2. Why this causes incorrect behavior:
#The pop() function removes elements from self.stack, but does not update self.min_val when the minimum value is removed.
#self.min_val is only updated during push(), so once the actual minimum is popped, the old min value remains.
#This causes get_min() to return incorrect results after popping the minimum.
