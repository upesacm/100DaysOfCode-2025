# Design a stack with auxiliary storage to maintain minimum element information while ensuring all operations remain O(1) complexity.
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

    def get_min(self):
        if self.min_stack:
            return self.min_stack[-1]
        return None

print("Enter operations like: push 5, push 2, getmin, pop")
print("Type 'exit' to stop input")

stack = MinStack()
while True:
    cmd = input("Command: ").strip().lower()
    if cmd == 'exit':
        break
    elif cmd.startswith("push"):
        val = int(cmd.split()[1])
        stack.push(val)
    elif cmd == "pop":
        stack.pop()
    elif cmd == "getmin":
        print(stack.get_min())
