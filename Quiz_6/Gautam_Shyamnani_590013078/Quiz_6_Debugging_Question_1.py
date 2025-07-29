class MinStack:
    def __init__(self):
        # Each item in the stack is a tuple: (value, current_min)
        self.stack = []

    def push(self, val):
        if not self.stack:
            # If stack is empty, current value is also the minimum
            self.stack.append((val, val))
        else:
            current_min = min(val, self.stack[-1][1])
            self.stack.append((val, current_min))

    def pop(self):
        if self.stack:
            # Return only the value part of the tuple
            return self.stack.pop()[0]
        else:
            print("Stack is empty!")
            return None

    def get_min(self):
        if self.stack:
            return self.stack[-1][1]
        else:
            print("Stack is empty!")
            return float("inf")


# 🎯 Sample usage and test cases
min_stack = MinStack()
min_stack.push(5)
min_stack.push(2)
min_stack.push(8)

print("Current Min:", min_stack.get_min())  # Expected: 2

print("Popped:", min_stack.pop())  # Pops 8
print("Popped:", min_stack.pop())  # Pops 2

print("Current Min after popping minimum:", min_stack.get_min())  # Expected: 5
