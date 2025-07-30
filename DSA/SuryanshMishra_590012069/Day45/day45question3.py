# 3. Find Maximum Element in a Queue
# A problem that teaches queue optimization techniques and demonstrates maximum value detection using efficient traversal algorithms for extremum finding in linear data structures.

# Given a queue of integers, find and return the maximum element present without altering the queue structure. This operation is fundamental in optimization problems and data analysis where you need to identify peak values within queue datasets. The technique requires understanding comparative traversal methods that track maximum values while processing queue elements sequentially. This concept is essential in performance monitoring, threshold detection, and data mining where maximum value identification enables decision making and analytical insights from queue-based data streams.

# This teaches extremum detection algorithms and comparative traversal techniques that are essential for optimization analysis and efficient maximum value identification in queue structures.

# Your task: Implement queue traversal with maximum tracking to identify the largest element while preserving queue state and maintaining efficiency.

# Examples
# Input:

# [3, 5, 1, 2]
# Output:

# 5
# Input:

# [10, 7, 4]
# Output:

# 10
from queue import Queue

def find_max_in_queue(q: Queue) -> int:
    if q.empty():
        raise ValueError("Queue is empty.")

    max_val = float('-inf')
    size = q.qsize()

    for _ in range(size):
        element = q.get()
        max_val = max(max_val, element)
        q.put(element)
    return max_val