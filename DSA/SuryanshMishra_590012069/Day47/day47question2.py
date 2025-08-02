# 2. Insert Element at Front of Queue
# An operation that demonstrates priority queue behavior by adding elements to the front, which is useful in task reordering, interrupt handling, and control systems.

# Write a function to insert a given element at the front of a queue.

# This teaches front insertion, queue prioritization, and head adjustment techniques useful in data streams and real-time control queues.

# Your task: Add an element to the front of a queue and return the updated queue.

# Examples
# Input:

# Queue = [2, 3, 4], Insert = 1
# Output:

# [1, 2, 3, 4]
# Input:

# Queue = [7, 8], Insert = 6
# Output:

# [6, 7, 8]
from collections import deque

def insert_front(q: deque, value: int) -> deque:
    q.appendleft(value)
    return q