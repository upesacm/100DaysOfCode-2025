class MinStack:
    def __init__(self):
        self.stack = []
        self.min_stack = []

    def push(self, val):
        self.stack.append(val)
        # Push to min_stack if it's the new minimum
        if not self.min_stack or val <= self.min_stack[-1]:
            self.min_stack.append(val)

    def pop(self):
        if self.stack:
            val = self.stack.pop()
            if val == self.min_stack[-1]:
                self.min_stack.pop()
            return val

    def get_min(self):
        if self.min_stack:
            return self.min_stack[-1]
        return float("inf")

#line 2 was causing the bug
#line 12 was also having the bug
#min_val isn't recalculated when min element is popped, in order to fix we use a secondary stack (min_stack) to track the current minimum