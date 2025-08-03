from collections import deque
def merge_queues_alternately(q1, q2):
    result = deque()
    while q1 or q2:
        if q1:
            result.append(q1.popleft())
        if q2:
            result.append(q2.popleft())
    return result
# Test case:
queue1 = deque([1, 3, 5])
queue2 = deque([2, 4])
merged = merge_queues_alternately(queue1, queue2)
print(f"Merged queue: {list(merged)}")

# 1. Line(s) causing the bug: line 8 (`if q1:`) and line 10 (`if q2:`)
# 2. Why this causes incorrect behavior: checking `if q1:` or `if q2:` 
#    evaluates to True even if the deque is not empty but contains only falsy 
#    values like 0 or None. It should check `if len(q1) > 0:` or just rely on the 
#    loop structure with more precise control. However, this doesn't cause incorrect merging for numerical values — the actual logic is not buggy here, so there's no logical error in functionality. The test case merges correctly. Thus, **there is no actual bug present; the function works as intended.**
