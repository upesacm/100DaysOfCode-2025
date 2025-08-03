"""
QUEUE MERGE OPERATION BUG

1. Identify the specific line(s) causing the bug:
   - The issue is in these lines:
        while q1 or q2:
            if q1:
                result.append(q1.popleft())
            if q2:
                result.append(q2.popleft())
   - This code will continue to pull from one queue even if the other is empty, so the "alternating" pattern is broken once one queue runs out.

2. Why this causes incorrect behavior:
   - It does not keep the alternating pattern if the queues have different lengths; instead, it adds all elements from the remaining queue in sequence.

CORRECTED CODE BELOW:
"""

from collections import deque

def merge_queues_alternately(q1, q2):
    result = deque()
    # Use shallow copies so original queues are not exhausted
    deque1, deque2 = deque(q1), deque(q2)

    while deque1 and deque2:
        result.append(deque1.popleft())
        result.append(deque2.popleft())
    # Add remaining elements from either queue
    result.extend(deque1)
    result.extend(deque2)
    return result

# Test case
queue1 = deque([1, 3, 5])
queue2 = deque([2, 4])
merged = merge_queues_alternately(queue1, queue2)
print(f"Merged queue: {list(merged)}")
