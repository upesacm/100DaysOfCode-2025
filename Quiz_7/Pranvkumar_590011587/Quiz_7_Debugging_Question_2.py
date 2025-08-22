from collections import deque

# 2. Queue Merge Operation Bug 

def merge_queues_alternately(q1, q2):
    """
    Merges two queues alternately.
    """
    result = deque()
    #  This loop works as intended.
    # No real bug, but worth noting: the function **modifies the input queues**.
    while q1 or q2:
        if q1:
            result.append(q1.popleft())
        if q2:
            result.append(q2.popleft())
    return result

#  FIX: If you want to preserve original queues
def merge_queues_alternately_fixed(q1, q2):
    result = deque()
    temp_q1 = deque(q1)
    temp_q2 = deque(q2)
    while temp_q1 or temp_q2:
        if temp_q1:
            result.append(temp_q1.popleft())
        if temp_q2:
            result.append(temp_q2.popleft())
    return result


# Test Case for Merge Operation 
queue1 = deque([1, 3, 5])
queue2 = deque([2, 4])
merged = merge_queues_alternately(queue1, queue2)

print("\nOriginal Buggy Merge (modifies q1 and q2):")
print(f"Merged queue: {list(merged)}")
print(f"Original queue1 after merge: {list(queue1)}")  
print(f"Original queue2 after merge: {list(queue2)}")  

# Test fixed version
queue1 = deque([1, 3, 5])
queue2 = deque([2, 4])
merged_fixed = merge_queues_alternately_fixed(queue1, queue2)

print("\nFixed Merge (preserves q1 and q2):")
print(f"Merged queue: {list(merged_fixed)}")
print(f"Original queue1 preserved: {list(queue1)}")
print(f"Original queue2 preserved: {list(queue2)}")


# Explanation of Behavior:
# 1. Line: `q1.popleft()` and `q2.popleft()` 
#    These lines modify the original input queues.
#    This may be unexpected if queues are needed after the merge.
# 2. Not a logic bug, but a **design issue**. Fixed version avoids side effects.