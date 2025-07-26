class MaxStack:
    def __init__(self):
        """
        Initializes two stacks: one for all elements and one to track the max.
        """
        self.stack = []
        self.max_stack = []

    def push(self, value):
        """Pushes a value onto the stack and updates the max_stack."""
        self.stack.append(value)
        # If max_stack is empty or the new value is greater than or equal
        # to the current max, push it to the max_stack.
        if not self.max_stack or value >= self.max_stack[-1]:
            self.max_stack.append(value)

    def pop(self):
        """Pops a value from the stack and updates max_stack if needed."""
        if not self.stack:
            return None
        
        value = self.stack.pop()
        
        # If the popped value is the current max, pop it from max_stack too.
        if value == self.max_stack[-1]:
            self.max_stack.pop()
            
        return value

    def getMax(self):
        """Returns the current maximum element in O(1) time."""
        if not self.max_stack:
            return None
        return self.max_stack[-1]

# --- Test cases ---

# Example 1
stack1 = MaxStack()
stack1.push(3)
stack1.push(5)
stack1.push(2)
print(f"Current Max: {stack1.getMax()}") # Output: 5

# Example 2
stack1.pop() # Pops 2
print(f"After one pop, Max is: {stack1.getMax()}") # Output: 5
stack1.pop() # Pops 5
print(f"After two pops, Max is: {stack1.getMax()}") # Output: 3
