class MinStack:
    def __init__(self):
        self.stack = []
        self.min_val = float("inf")

    def push(self, val):
        self.stack.append(val)
        if val < self.min_val:
            self.min_val = val

    def pop(self):
        if self.stack:
            popped = self.stack.pop() # This line was alright for poping but it doesn't update the self.min_val
# So we added these Lines.
            if popped == self.min_val:
                if self.stack:
                    self.min_val = min(self.stack)
                else:
                    print("-1")
#What they do is that that once an element is poped it checkes if its the minimum and if it is then it runs the min function which tells us the min value.
            return popped

    def get_min(self):
        return self.min_val
min_stack = MinStack()
min_stack.push(5)
min_stack.push(2)
min_stack.push(8)
print(min_stack.get_min())  # Should print 2 = and actually does print two
min_stack.pop()
min_stack.pop()  # Popping the minimum element (2)
print(min_stack.get_min())  # Should print 5, but what does it print? = It still prints two as we haven't chnage the value of self.im_val , its still 2.
