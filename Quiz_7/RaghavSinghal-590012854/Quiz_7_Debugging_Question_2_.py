# 2. Queue Merge Operation Bug

# The following function is intended to merge two queues alternately (taking one element from each queue in turn). However, it has a logical error:


from collections import deque


def merge_queues_alternately(q1, q2):
    result = deque()
    turn = 0  

    while q1 or q2:
        if turn == 0 and q1:
            result.append(q1.popleft())
        elif turn == 1 and q2:
            result.append(q2.popleft())
        turn = 1 - turn

    return result



# Test case:
queue1 = deque([1, 3, 5])
queue2 = deque([2, 4])
merged = merge_queues_alternately(queue1, queue2)
print(f"Merged queue: {list(merged)}")

# Tasks:
# 1. Identify the specific line(s) causing the bug 
# 2. Why this causes incorrect behavior: