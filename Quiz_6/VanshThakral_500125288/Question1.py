class MinStack:
    def __init__(self):
        self.stack = []
        self.min_stack = []  # Stores current minimums

    def push(self, val):
        self.stack.append(val)
        if not self.min_stack or val <= self.min_stack[-1]:
            self.min_stack.append(val)

    def pop(self):
        if self.stack:
            popped = self.stack.pop()
            if popped == self.min_stack[-1]:
                self.min_stack.pop()
            return popped

    def get_min(self):
        return self.min_stack[-1] if self.min_stack else None
 # Problematic line
  #  def pop(self):
     # if self.stack:
        # popped = self.stack.pop()
        # return popped
#AND
 #def push(self, val):
    #self.stack.append(val)
    #if val < self.min_val:
        #self.min_val = val

# Why This Causes Incorrect Behavior:
# When you pop() a value, you're not updating self.min_val.
# If the minimum value is removed (e.g. 2 in your test), the stack still thinks min_val is 2.
# There’s no tracking of previous minimums, so get_min() gives incorrect results after popping the min element.
