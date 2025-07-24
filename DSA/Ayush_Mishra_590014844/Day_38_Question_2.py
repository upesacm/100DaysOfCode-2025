class MinStack:
    def __init__(self):
        self.stack = []
        self.minStack = []
    
    def push(self, val):
        self.stack.append(val)
        if not self.minStack or val <= self.minStack[-1]:
            self.minStack.append(val)
    
    def pop(self):
        if self.stack:
            if self.stack[-1] == self.minStack[-1]:
                self.minStack.pop()
            self.stack.pop()
    
    def getMin(self):
        return self.minStack[-1] if self.minStack else None

s = MinStack()
while True:
    print("\n1. Push\n2. Pop\n3. Get Min\n4. Exit")
    ch = int(input("Enter choice: "))
    if ch == 1:
        val = int(input("Enter value: "))
        s.push(val)
    elif ch == 2:
        s.pop()
    elif ch == 3:
        print("Minimum element:", s.getMin())
    elif ch == 4:
        break
    else:
        print("Invalid choice")
