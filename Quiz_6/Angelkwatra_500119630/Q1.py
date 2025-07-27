class Q1:
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
#1. Identify the bug in the stack condition:
# while stack and prices[stack[-1]] >= prices[i]:

# 2. Why this causes incorrect behavior:
# The logic pops larger or equal prices, but stock span should count all previous prices that are smaller or equal to current.
# By removing higher prices, we lose the history of spans that should’ve been counted.
