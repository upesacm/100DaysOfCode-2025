# 1. Reverse First K Elements of Queue
# A problem that demonstrates partial queue manipulation techniques and teaches selective element reversal using auxiliary data structures while preserving the First-In-First-Out principle for remaining elements.

# Given a queue and an integer k, reverse the first k elements of the queue while maintaining the order of the rest of the elements. This operation challenges traditional queue behavior by requiring selective modification of specific positions without disrupting the overall FIFO structure. The technique is fundamental in data stream processing and buffer management where you need to reorder specific segments while preserving the sequence of unaffected elements. Understanding this concept is crucial for packet processing, task scheduling, and priority queue modifications where partial reordering optimizes processing efficiency without complete restructuring.

# This teaches selective queue manipulation algorithms and partial reversal techniques that are essential for stream processing and efficient queue segment modification operations.

# Your task: Use auxiliary data structures to reverse the first k queue elements while maintaining FIFO order for the remaining elements.

# Examples
# Input:

# Queue = [1, 2, 3, 4, 5], k = 3
# Output:

# [3, 2, 1, 4, 5]
# Input:

# Queue = [10, 20, 30], k = 2
# Output:

# [20, 10, 30]
from collections import deque

def reverseFirstK(queue, k):
    stack = []
    for _ in range(k):
        stack.append(queue.popleft())

    while stack:
        queue.append(stack.pop())
    
    for _ in range(len(queue) - k):
        queue.append(queue.popleft())
    
    return list(queue)
