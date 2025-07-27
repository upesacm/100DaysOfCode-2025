#1. Line(s) Causing the Bug:

  #  def pop(self):
   #     if self.stack:
    #        popped = self.stack.pop()
#            return popped

# def push(self, val):
#        self.stack.append(val)
 ##          self.min_val = val


# 2. Why This Causes Incorrect Behavior:
#When popping the minimum value (2), self.min_val is not updated.

#self.min_val is only set when a new minimum is pushed, but never adjusted on pop, even if the min element is removed.



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
            popped = self.stack.pop()
            return popped

    def get_min(self):
        return self.min_val


# Test case that reveals the bug:
min_stack = MinStack()
min_stack.push(5)
min_stack.push(2)
min_stack.push(8)
print(min_stack.get_min())  # Should print 2
min_stack.pop()
min_stack.pop()  # Popping the minimum element (2)
print(min_stack.get_min())  # Should print 5, but what does it print?
