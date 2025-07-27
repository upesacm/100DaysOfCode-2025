# 1. Identify the specific line(s) causing the bug 
# -- while stack and prices[stack[-1]] >= prices[i]:

#2. Why this causes incorrect behavior:
# -- The min_val is updated only when pushing a smaller value.
#    But when popping, the code does not check if the popped value was the current  minimum.
#    So if the minimum value is removed, min_val remains unchanged — leading to    incorrect results in get_min().

#correct code-- 
class MinStack:
    def _init_(self):
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
        if self.min_stack:
            return self.min_stack[-1]
        return float("inf")
