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
            '''This needs this logic which changes the min_val when the minimum element is popped
                in the earlier version pop was just removing the top element and not changing the
                min_val accordingly.'''
            if popped == self.min_val:
                self.min_val = min(self.stack) if self.stack else float("inf")
            return popped

    def get_min(self):
        return self.min_val


# Test case that reveals the bug:
min_stack = MinStack()
min_stack.push(5)
min_stack.push(2)
min_stack.push(8)
print(min_stack.get_min())  # Should print 2
min_stack.pop()
min_stack.pop()  # Popping the minimum element (2)
print(min_stack.get_min())  # Should print 5, but what does it print?
