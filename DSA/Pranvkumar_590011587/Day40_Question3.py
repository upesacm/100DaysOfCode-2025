class MaxStack:
    def __init__(self):
        self.stack = []
        self.max_stack = []
    def push(self, x):
        self.stack.append(x)
        if not self.max_stack or x >= self.max_stack[-1]:
            self.max_stack.append(x)
    def pop(self):
        if not self.stack:
            return None
        val = self.stack.pop()
        if val == self.max_stack[-1]:
            self.max_stack.pop()
        return val
    def getMax(self):
        if not self.max_stack:
            return None
        return self.max_stack[-1]

# Example usage:
s = MaxStack()
s.push(3)
s.push(5)
s.push(2)
print(s.getMax())  
s.pop()
print(s.getMax()) 
s.pop()
print(s.getMax()) 