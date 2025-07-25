class max_stack:
    def __init__(self):
        self.main=[]
        self.maxes=[]
    def push(self,x):
        self.main.append(x)
        if not self.maxes or x>=self.maxes[-1]:
            self.maxes.append(x)
    def pop(self):
        if not self.main:
            return None
        val=self.main.pop()
        if val == self.maxes[-1]:
            self.maxes.pop()
        return val
    def getMax(self):
        if not self.maxes:
            return None
        return self.maxes[-1]