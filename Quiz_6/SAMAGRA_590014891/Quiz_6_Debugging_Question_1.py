class MinStack:
    def __init__(self):
        self.stack = []
        self.min_val = float("inf")  # Tracks only a single minimum value

    def push(self, val):
        self.stack.append(val)
        if val < self.min_val:
            self.min_val = val  # Updates min_val only when a new lower value is pushed

    def pop(self):
        if self.stack:
            popped = self.stack.pop()
            # Bug: This does not update min_val when the minimum element is removed
            # If the popped element was the minimum, min_val will now be incorrect
            return popped

    def get_min(self):
        return self.min_val  # Returns the stored min_val, which may be stale after pop()


# Test case that reveals the bug:
min_stack = MinStack()
min_stack.push(5)      # Stack = [5], min_val = 5
min_stack.push(2)      # Stack = [5, 2], min_val = 2
min_stack.push(8)      # Stack = [5, 2, 8], min_val = 2
print(min_stack.get_min())  # Should print 2

min_stack.pop()        # Pops 8, min_val remains 2 (correct)
min_stack.pop()        # Pops 2, which was the minimum, but min_val still remains 2 (incorrect)
print(min_stack.get_min())  # Should print 5, but it prints 2 due to stale min_val
