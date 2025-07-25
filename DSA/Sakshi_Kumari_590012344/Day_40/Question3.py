class MaxStack:
    def __init__(self):
        self.mainStack = []
        self.maxStack = []

    def push(self, value):
        self.mainStack.append(value)
        if not self.maxStack or value >= self.maxStack[-1]:
            self.maxStack.append(value)
        else:
            self.maxStack.append(self.maxStack[-1])

    def pop(self):
        if self.mainStack:
            self.maxStack.pop()
            return self.mainStack.pop()
        return None

    def top(self):
        if self.mainStack:
            return self.mainStack[-1]
        return None

    def getMax(self):
        if self.maxStack:
            return self.maxStack[-1]
        return None
