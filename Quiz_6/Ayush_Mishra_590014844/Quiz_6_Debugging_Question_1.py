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
        return None
min_stack = MinStack()
min_stack.push(5)
min_stack.push(2)
min_stack.push(8)
print(min_stack.get_min()) 
min_stack.pop()
min_stack.pop()
print(min_stack.get_min())
