# 1. if val < self.min_val:
#     self.min_val = val   ✅ This line sets min, but no way to update it when min is popped!


#    popped = self.stack.pop()
#    return popped    ❌ It pops without checking if the popped value was the minimum



# 2. The bug is in how the minimum value min_val is handled during pop(). It updates the minimum only on push, but never recomputes it when the minimum element is popped.
#   Once the minimum is popped, min_val is never updated, so it still returns the old (incorrect) minimum.

# Correct Code will be
class MinStack:
    def __init__(self):
        self.stack = []
        self.min_stack = []

    def push(self, val):
        self.stack.append(val)
        if not self.min_stack or val <= self.min_stack[-1]:
            self.min_stack.append(val)

    def pop(self):
        if self.stack:
            popped = self.stack.pop()
            if popped == self.min_stack[-1]:
                self.min_stack.pop()
            return popped

    def get_min(self):
        return self.min_stack[-1] if self.min_stack else float("inf")
