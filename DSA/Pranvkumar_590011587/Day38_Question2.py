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

    def getMin(self):
        if self.min_stack:
            return self.min_stack[-1]
        return None

# Examples
ms = MinStack()
ms.push(5); ms.push(3); ms.push(7)
print(ms.getMin())  
ms = MinStack()
ms.push(8); ms.push(2); ms.push(6)
ms.pop()
print(ms.getMin()) 