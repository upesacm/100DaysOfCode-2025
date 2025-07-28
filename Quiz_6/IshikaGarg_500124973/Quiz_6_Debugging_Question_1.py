1. Lines that cause problems:
self.min_val = float("inf")   
if val < self.min_val:     


2.
This causes incorrect behavior:
The class does not update min_val when popping the current minimum.

So when 2 (the minimum) is popped, min_val still remains 2, which is incorrect — it should be updated to 5 (the next smallest).

corrected code:
class MinStack:
    def __init__(self):
        self.stack = []

    def push(self, val):
        # Store (val, current_min) in stack
        current_min = val if not self.stack else min(val, self.stack[-1][1])
        self.stack.append((val, current_min))

    def pop(self):
        if self.stack:
            return self.stack.pop()[0]

    def get_min(self):
        if self.stack:
            return self.stack[-1][1]
