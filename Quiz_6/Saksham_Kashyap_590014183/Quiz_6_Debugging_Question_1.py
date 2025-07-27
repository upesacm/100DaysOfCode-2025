# BUG: Old single min_val doesn't update on pop(), so get_min() returns stale value.
#    > If you pop the minimum, it must be updated—but old code only updated min_val on push.
#
# FIX: Use a second stack (min_stack) to store the minimum so far at each push.
#    > Now, pop from min_stack whenever you pop the current minimum.
#    > This updates the min in O(1) time after every push/pop.
#
# RESULT: get_min() always returns the correct, up-to-date minimum of the stack.
class MinStack:
    def __init__(self):
        self.stack = []      # The actual values.
        self.min_stack = []  # Keep track of the minimum "so far" at each push.

    def push(self, val):
        self.stack.append(val)
        # Push to min_stack if empty, or val <= current min.
        if not self.min_stack or val <= self.min_stack[-1]:
            self.min_stack.append(val)
        # At every push, min_stack[-1] holds the min of all values so far.
        # So this records history of "mins" efficiently.

    def pop(self):
        if self.stack:
            popped = self.stack.pop()
            # If we're popping the current min, pop it from the min_stack too!
            if popped == self.min_stack[-1]:
                self.min_stack.pop()
            return popped
        # This means get_min() always reflects the min *of current stack*.

    def get_min(self):
        # Return the current minimum in O(1):
        if self.min_stack:
            return self.min_stack[-1]
        # If stack is empty, you could choose to return None or throw an error.

# ----------------------------- EXPLANATION with TEST CASE -----------------------------
# This will pass all test cases and is optimal.

min_stack = MinStack()
min_stack.push(5)    # stack: [5],     min_stack: [5]
min_stack.push(2)    # stack: [5, 2],  min_stack: [5, 2]
min_stack.push(8)    # stack: [5, 2, 8], min_stack: [5, 2] (8 > 2, not pushed)

print(min_stack.get_min())  # Output: 2 (correct, still in stack)
min_stack.pop()             # Pops 8
min_stack.pop()             # Pops 2 (the min!), so min_stack pops too
print(min_stack.get_min())  # Output: 5 (correct, after popping previous min)
