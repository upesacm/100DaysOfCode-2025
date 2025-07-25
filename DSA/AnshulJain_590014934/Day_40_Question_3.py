class MaxStack:
    def __init__(self):
        self.stack = []
        self.max_stack = []
    def push(self, val):
        self.stack.append(val)
        if not self.max_stack or val >= self.max_stack[-1]:
            self.max_stack.append(val)
    def pop(self):
        if self.stack:
            val = self.stack.pop()
            if val == self.max_stack[-1]:
                self.max_stack.pop()
    def getMax(self):
        if self.max_stack:
            return self.max_stack[-1]
        return None
s = MaxStack()
ops = input().lower().replace(':', '').split('→')
commands = ops[0].strip().split(',')
for cmd in commands:
    if 'push' in cmd:
        val = int(cmd.strip().split()[1])
        s.push(val)
    elif 'pop' in cmd:
        s.pop()
if len(ops) > 1 and 'getmax' in ops[1].strip():
    print(s.getMax())
