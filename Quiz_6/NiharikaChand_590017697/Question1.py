"""
1. Line in push: if val < self.min_val: self.min_val = val
   pop() method: it does not update self.min_val after popping

2. When the minimum value (2) is popped, min_val is not recalculated from the remaining elements.
"""

#corrected version
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
            if popped == self.min_val:
                self.min_val = min(self.stack) if self.stack else float("inf")    # recalculate new min
            return popped

    def get_min(self):
        return self.min_val

