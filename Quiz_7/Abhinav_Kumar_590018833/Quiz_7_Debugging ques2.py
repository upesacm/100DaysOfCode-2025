# The following function is intended to merge two queues alternately (taking one element from each queue in turn). However, it has a logical error:



# from collections import deque


# def merge_queues_alternately(q1, q2):
#     result = deque()

#     while q1 or q2:
#         if q1:
#             result.append(q1.popleft())
#         if q2:
#             result.append(q2.popleft())

#     return result


# # Test case:
# queue1 = deque([1, 3, 5])
# queue2 = deque([2, 4])
# merged = merge_queues_alternately(queue1, queue2)
# print(f"Merged queue: {list(merged)}")

# Tasks:

# 1. Identify the specific line(s) causing the bug 
# 2. Why this causes incorrect behavior:

from collections import deque

def merge_queues_alternately(q1, q2):
    result = deque()

    while q1 or q2:
        if q1:
            result.append(q1.popleft())
        if q2:
            result.append(q2.popleft())

    return result

queue_a = deque(['A', 'B', 'C'])
queue_b = deque([1, 2, 3, 4, 5])

print(f"Original Q1: {list(queue_a)}")
print(f"Original Q2: {list(queue_b)}")
merged_queue = merge_queues_alternately(queue_a, queue_b)

print(f"\nMerged Queue: {list(merged_queue)}")

print(f"\nOriginal Q1 after merge: {list(queue_a)}")
print(f"Original Q2 after merge: {list(queue_b)}")