class MinStack:
    def __init__(self):
        self.stack = []
        self.min_stack = []  # Additional stack to track minimums
        # self.min_val = float("inf")  # Removed - this was the root cause

    def push(self, val):
        self.stack.append(val)
        # Track minimum in a separate stack
        if not self.min_stack or val <= self.min_stack[-1]:
            self.min_stack.append(val)
        # Old buggy version:
        # if val < self.min_val:
        #     self.min_val = val

    def pop(self):
        if self.stack:
            popped = self.stack.pop()
            # Update min_stack if we're popping the current minimum
            if popped == self.min_stack[-1]:
                self.min_stack.pop()
            return popped
        # Old buggy version didn't update min_val after pop

    def get_min(self):
        return self.min_stack[-1] if self.min_stack else None
        # Old buggy version:
        # return self.min_val  # Would return stale minimum after pops


# Test case that reveals the bug:
min_stack = MinStack()
min_stack.push(5)
min_stack.push(2)
min_stack.push(8)
print(min_stack.get_min())  # Prints 2 (correct)
min_stack.pop()
min_stack.pop()  # Popping the minimum element (2)
print(min_stack.get_min())  # Now correctly prints 5
