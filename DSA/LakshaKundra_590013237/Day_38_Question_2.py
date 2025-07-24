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
            val = self.stack.pop()
            if val == self.min_stack[-1]:
                self.min_stack.pop()

    def top(self):
        if self.stack:
            return self.stack[-1]
        return None

    def get_min(self):
        if self.min_stack:
            return self.min_stack[-1]
        return None

s1 = MinStack()
s1.push(5)
s1.push(3)
s1.push(7)
print(s1.get_min())

s2 = MinStack()
s2.push(8)
s2.push(2)
s2.push(6)
s2.pop()
print(s2.get_min())
