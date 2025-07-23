class Stack:
    def __init__(self):
        self.items = []

    def push(self, value):
        self.items.append(value)

    def pop(self):
        if self.is_empty():
            return None
        return self.items.pop()

    def peek(self):
        if self.is_empty():
            return None
        return self.items[-1]

    def is_empty(self):
        return len(self.items) == 0

    def display(self):
        for item in reversed(self.items):
            print(item)

def sort_stack(stack):
    temp_stack = Stack()

    while not stack.is_empty():
        current = stack.pop()

        while not temp_stack.is_empty() and temp_stack.peek() > current:
            stack.push(temp_stack.pop())

        temp_stack.push(current)

    while not temp_stack.is_empty():
        stack.push(temp_stack.pop())

