# BUG:
# - Using `popleft()` directly on q1 and q2 modifies the original input queues.
# - If original queues are needed after merge, this leads to data loss.

# WHY THIS CAUSES INCORRECT BEHAVIOR:
# - Mutating input queues directly is unsafe if they are reused later.
# - The function should not destroy inputs unless explicitly stated.

# FIX:
# - Use local copies of input queues for merging.
# - Result remains the same, but inputs are preserved.

from collections import deque

def merge_queues_alternately(q1, q2):
    result = deque()
    q1_copy = deque(q1)
    q2_copy = deque(q2)

    while q1_copy or q2_copy:
        if q1_copy:
            result.append(q1_copy.popleft())
        if q2_copy:
            result.append(q2_copy.popleft())

    return result

# Test case
queue1 = deque([1, 3, 5])
queue2 = deque([2, 4])
merged = merge_queues_alternately(queue1, queue2)
print(f"Merged queue: {list(merged)}")      # Output: [1, 2, 3, 4, 5]
print(f"Original q1: {list(queue1)}")       # Output: [1, 3, 5]
print(f"Original q2: {list(queue2)}")       # Output: [2, 4]