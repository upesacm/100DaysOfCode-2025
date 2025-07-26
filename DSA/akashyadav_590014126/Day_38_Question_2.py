class min_stack:
    def __init__(self):
        self.stack=[]
        self.min_stack=[]

    def push(self,x):
        self.stack_append(x)
        if not self.min_stack or x <= self.min_stack[-1]:
            self.min_stack.append(x)
        
        else:
            self.min_stack.append(self.min_stack[-1])

    def pop(self):
        self.stack.pop()
        self.min_stack

    def top(self):
        return self.stack[-1]
    
    def getMin(self):
        return self.min_stack[-1]
    