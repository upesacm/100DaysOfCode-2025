class MinStack:
    def __init__(self):
        self.stack = []
        self.min_stack = []  # helper stack to track min values

    def push(self, val):
        self.stack.append(val)
        # push to min_stack if it's empty or val <= current min
        if not self.min_stack or val <= self.min_stack[-1]:
            self.min_stack.append(val)

    def pop(self):
        if self.stack:
            popped = self.stack.pop()
            if popped == self.min_stack[-1]:
                self.min_stack.pop()  # remove corresponding min
            return popped

    def get_min(self):
        if self.min_stack:
            return self.min_stack[-1]
        return float("inf")  # or raise error if needed
