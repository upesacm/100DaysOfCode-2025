1. Identify the specific line(s) causing the bug 
def pop(self):
    if self.stack:
        popped = self.stack.pop()
        return popped
      It does not update min_val when the current minimum is popped.
2. Why this causes incorrect behavior:
When I pop the minimum element (which is 2), the code doesn't update min_val, so get_min() still gives 2 even though it's no longer in the stack. 
This gives the wrong result and breaks the logic of the Min Stack.

