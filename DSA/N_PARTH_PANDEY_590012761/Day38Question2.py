class MinStack:
    def __init__(self):
        self.stack = []
        self.min_stack = []

    def push(self, val):
        self.stack.append(val)
        if not self.min_stack or val <= self.min_stack[-1][0]:
            # Store both the value and its count
            if self.min_stack and val == self.min_stack[-1][0]:
                self.min_stack[-1] = (val, self.min_stack[-1][1] + 1)
            else:
                self.min_stack.append((val, 1))

    def pop(self):
        if not self.stack:
            return None
        val = self.stack.pop()
        if val == self.min_stack[-1][0]:
            if self.min_stack[-1][1] > 1:
                self.min_stack[-1] = (val, self.min_stack[-1][1] - 1)
            else:
                self.min_stack.pop()
        return val

    def top(self):
        if not self.stack:
            return None
        return self.stack[-1]

    def getMin(self):
        if not self.min_stack:
            return None
        return self.min_stack[-1][0]


if __name__ == "__main__":
    min_stack = MinStack()
    operations = []
    
    print("Enter stack operations (push <nums>, pop, top, getMin, or 'exit' to quit):")
    while True:
        operation = input("> ").strip().lower()
        if operation == 'exit':
            break
        
        if operation.startswith('push'):
            try:
                nums = list(map(int, operation.split()[1:]))
                for num in nums:
                    min_stack.push(num)
                    operations.append(f"push {num}")
            except (IndexError, ValueError):
                print("Invalid push operation. Usage: push <num1> <num2> ...")
        elif operation == 'pop':
            result = min_stack.pop()
            operations.append("pop")
            print(f"Popped: {result}")
        elif operation == 'top':
            result = min_stack.top()
            operations.append("top")
            print(f"Top element: {result}")
        elif operation == 'getmin':
            result = min_stack.getMin()
            operations.append("getMin")
            print(f"Minimum element: {result}")
        else:
            print("Invalid operation. Use push, pop, top, getMin, or exit")
    
    print("\nOperation history:")
    for op in operations:
        print(op)