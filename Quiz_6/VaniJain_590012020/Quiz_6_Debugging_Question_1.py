Tasks:

1. Identify the specific line(s) causing the bug 
2. Why this causes incorrect behavior:

task 1
def pop(self):
    if self.stack:
        popped = self.stack.pop()
        return popped

task2
min_val is a single global tracker.
Once set to a minimum value (e.g., 2), there's no mechanism to recalculate the next minimum when that value is popped.
Therefore, get_min() keeps returning an outdated value, breaking the logic of the Min Stack.
