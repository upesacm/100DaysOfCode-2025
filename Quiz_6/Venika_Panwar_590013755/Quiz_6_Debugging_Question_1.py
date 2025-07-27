# Solution for question 1:

# BUG:
# - min_val was only updated when pushing new elements.
# - If the minimum element was popped, min_val was not recalculated.
# - So get_min() returned outdated values after popping the minimum.

# FIX:
# - Use an extra stack (min_stack) to keep track of the minimum at every push.
# - When popping, if the popped value is equal to the top of min_stack, pop that too.
# - This ensures get_min() always gives the correct minimum in O(1) time.

class MinStack:
    def __init__(self):
        self.stack = []
        self.min_stack = []

    def push(self, val):
        self.stack.append(val)
        # Push to min_stack if it's empty or the new value is <= current min
        if not self.min_stack or val <= self.min_stack[-1]:
            self.min_stack.append(val)

    def pop(self):
        if self.stack:
            popped = self.stack.pop()
            # Also pop from min_stack if we removed the current min
            if popped == self.min_stack[-1]:
                self.min_stack.pop()
            return popped

    def get_min(self):
        # Return the current minimum, or None if the stack is empty
        return self.min_stack[-1] if self.min_stack else None

# Test case
min_stack = MinStack()
min_stack.push(5)
min_stack.push(2)
min_stack.push(8)
print(min_stack.get_min())  # Output: 2
min_stack.pop()             # Pops 8
min_stack.pop()             # Pops 2 (min)
print(min_stack.get_min())  # Output: 5 (correct)
