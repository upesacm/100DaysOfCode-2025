#def pop(self):
# if self.stack:
 #       popped = self.stack.pop()
 #       return popped
#def get_min(self):
  #return self.min_val
#These lines do not update min_val after popping an element.

#answer 2
#The min_val is only updated in push(), but never updated in pop().
#So when the minimum element is removed, min_val remains the same.

#correct code - 
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
            popped = self.stack.pop()
            if popped == self.min_stack[-1]:
                self.min_stack.pop()
            return popped

    def get_min(self):
        if self.min_stack:
            return self.min_stack[-1]
        return None
