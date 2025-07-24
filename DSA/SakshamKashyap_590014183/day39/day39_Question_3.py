class TwoStacks:
    def __init__(self, n):
        self.size = n
        self.arr = [None] * n
        self.top1 = -1
        self.top2 = self.size

    def push1(self, value):
        """Pushes a value onto the first stack."""
        # Check if there is at least one empty space between the stacks
        if self.top1 < self.top2 - 1:
            self.top1 += 1
            self.arr[self.top1] = value
        else:
            print("Stack Overflow")

    def push2(self, value):
        """Pushes a value onto the second stack."""
        # Check if there is at least one empty space between the stacks
        if self.top1 < self.top2 - 1:
            self.top2 -= 1
            self.arr[self.top2] = value
        else:
            print("Stack Overflow")

    def pop1(self):
        """Pops a value from the first stack."""
        if self.top1 >= 0:
            value = self.arr[self.top1]
            self.top1 -= 1
            return value
        else:
            print("Stack Underflow")
            return None

    def pop2(self):
        """Pops a value from the second stack."""
        if self.top2 < self.size:
            value = self.arr[self.top2]
            self.top2 += 1
            return value
        else:
            print("Stack Underflow")
            return None
    
    def get_stack1(self):
        """Helper to view the contents of stack 1."""
        return self.arr[0:self.top1 + 1]

    def get_stack2(self):
        """Helper to view the contents of stack 2."""
        # The stack grows from right to left, so we reverse it for printing
        return self.arr[self.top2:self.size][::-1]

# --- Test cases ---
ts = TwoStacks(5)

ts.push1(1)
ts.push1(2)
ts.push2(9)
ts.push2(8)

print(f"Stack 1: {ts.get_stack1()}")
print(f"Stack 2: {ts.get_stack2()}")

ts.push1(3)
print(f"Stack 1 after push(3): {ts.get_stack1()}")

# This will cause an overflow
ts.push2(7)

# Pop from stack 2
print(f"Popped from Stack 2: {ts.pop2()}")
print(f"Stack 2 after pop: {ts.get_stack2()}")
