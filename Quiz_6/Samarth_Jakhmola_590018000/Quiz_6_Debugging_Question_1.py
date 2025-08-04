# 1. Identify the specific line(s) causing the bug:
# The issue lies in the pop method:
# It removes an element from the stack but does not update self.min_val when the minimum element is popped.

# 2. Why this causes incorrect behavior:
# Since self.min_val is not updated after popping the minimum element (e.g., 2),
# get_min() continues to return the old minimum even though it's no longer in the stack.
# This breaks the O(1) minimum retrieval correctness after a min element is removed.

# Fix Suggestion:
# To maintain O(1) time for get_min(), store (val, current_min) as a tuple in the stack.
# That way, you always have the current minimum at each level.
