#Bug :
#min_val is not updated correctly when the current minimum is popped.
#reason :
#When we pop the minimum element, min_val is not updated to the next smallest. So get_min() still returns the old (now removed) minimum.
# correct code :
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
        if self.min_stack:
            return self.min_stack[-1]
