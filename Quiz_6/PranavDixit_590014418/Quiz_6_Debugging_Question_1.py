class MinStack:
    def __init__(self):
        self.stack = []
        self.min_stack = []

    def push(self, val):
        self.stack.append(val)
        # If min_stack is empty or new val is <= last min, push val
        if not self.min_stack or val <= self.min_stack[-1]:
            self.min_stack.append(val)

    def pop(self):
        if not self.stack:
            return None
        popped = self.stack.pop()
        if popped == self.min_stack[-1]:
            self.min_stack.pop()
        return popped

    def get_min(self):
        if not self.min_stack:
            return None
        return self.min_stack[-1]

# Test the fixed code  
min_stack = MinStack()
min_stack.push(5)
min_stack.push(2)
min_stack.push(8)
print(min_stack.get_min())  # Should print 2

min_stack.pop()  # Pops 8
min_stack.pop()  # Pops 2 (the minimum)
print(min_stack.get_min())  # Should print 5



# 1. The bug is that min_val is not updated on pop, so when the minimum is removed,
#    get_min() can return a stale (incorrect) value that is no longer in the stack.

# 2. This causes incorrect behavior because the code cannot "remember"
#    previous minimums when the current minimum is popped.

#    The fix is to use an auxiliary stack to store all minimum values
#    as the stack grows/shrinks, so you can always get O(1) minimum queries
#    even after popping the previous minimum.


