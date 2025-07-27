# Solution for question 1:

class MinStack:
    def __init__(self):
        self.stack = []
        self.min_stack = []  # Maintain an auxiliary stack for minimums

    def push(self, val):
        self.stack.append(val)
        # Push to min_stack if it's empty or val <= top of min_stack
        if not self.min_stack or val <= self.min_stack[-1]:
            self.min_stack.append(val)

    def pop(self):
        if self.stack:
            popped = self.stack.pop()
            # If popped value was the current minimum, remove it from min_stack too
            if popped == self.min_stack[-1]:
                self.min_stack.pop()
            return popped

    def get_min(self):
        # Always return the top of min_stack as the current minimum
        return self.min_stack[-1] if self.min_stack else float("inf")

# Task 1️:
# Bug Summary:
# Buggy line: `self.min_val = val` (in push), and no update in `pop()`

# Task 2️:
# Why it's wrong:
#     - Once the min is popped, `min_val` is never updated, so get_min() becomes stale

# Fix:
#     - Use a secondary stack (`min_stack`) to keep track of all minimums
#     - On pop, remove from `min_stack` only if it's the current minimum
