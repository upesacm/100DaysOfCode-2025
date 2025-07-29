# 1. Stack Implementation Bug

# The following implementation is intended to create a Min Stack that supports getting the minimum element in O(1) time. However, it contains bugs. Identify the error and explain why it causes incorrect behavior:


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
        return self.min_stack[-1] if self.min_stack else None



# Test case that reveals the bug:
min_stack = MinStack()
min_stack.push(5)
min_stack.push(2)
min_stack.push(8)
print(min_stack.get_min())  # Should print 2
min_stack.pop()
min_stack.pop()  # Popping the minimum element (2)
print(min_stack.get_min())  # Should print 5, but what does it print?

# Tasks:
# 1. Identify the specific line(s) causing the bug 
# The pop function
# 2. Why this causes incorrect behavior:
# Because it was not checking and changing the min stack