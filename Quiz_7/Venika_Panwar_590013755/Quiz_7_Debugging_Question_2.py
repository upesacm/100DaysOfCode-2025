# Solution for Question 2:

# Task 1:
# BUGGY LINE (Original Code):
# Line 10–11: `q1.popleft()` and `q2.popleft()`  -> Directly mutates inputs.

# Task 2:
# WHY THIS CAUSES INCORRECT BEHAVIOR:
# - Input queues `q1` and `q2` are destroyed during the merge.
# - Unsafe if queues are reused or needed after merging.

# FIX:
# - Create local copies (`q1_copy`, `q2_copy`) and operate on them instead.

from collections import deque

def merge_queues_alternately(q1, q2):
    """Merge two queues alternately without modifying original input queues."""
    result = deque()
    q1_copy = deque(q1)  # Preserve original q1
    q2_copy = deque(q2)  # Preserve original q2

    while q1_copy or q2_copy:
        if q1_copy:
            result.append(q1_copy.popleft())  # Safe mutation on local copy
        if q2_copy:
            result.append(q2_copy.popleft())

    return result

# Test case
queue1 = deque([1, 3, 5])
queue2 = deque([2, 4])
merged = merge_queues_alternately(queue1, queue2)
print(f"Merged queue: {list(merged)}")   #  Output: [1, 2, 3, 4, 5]
print(f"Original q1: {list(queue1)}")    #  Output: [1, 3, 5]
print(f"Original q2: {list(queue2)}")    #  Output: [2, 4]

