# 1. Find Minimum Element in a Queue
# A problem that introduces queue optimization techniques and teaches minimum value detection using efficient traversal algorithms for extremum identification in linear data structures with comparative analysis methods.

# Given a queue of integers, find and return the minimum element present without altering the queue structure. This operation is fundamental in optimization problems and data analysis where you need to identify lowest values within queue datasets for threshold detection and boundary analysis. The technique requires understanding comparative traversal methods that track minimum values while processing queue elements sequentially through systematic comparison operations. This concept is essential in resource optimization, cost analysis, and performance monitoring where minimum value identification enables efficient decision making and analytical insights from queue-based data streams.

# This teaches extremum detection algorithms and comparative traversal techniques that are essential for optimization analysis and efficient minimum value identification in queue structures.

# Your task: Implement queue traversal with minimum tracking to identify the smallest element while preserving queue state and maintaining computational efficiency.

# Examples
# Input:

# [4, 2, 7, 1]
# Output:

# 1
# Input:

# [9, 3]
# Output:

# 3
from queue import Queue

def find_min_in_queue(q: Queue) -> int:
    if q.empty():
        raise ValueError("Queue is empty")
    
    temp = Queue()
    minimum = None

    while not q.empty():
        item = q.get()
        if minimum is None or item < minimum:
            minimum = item
        temp.put(item)
    
    while not temp.empty():
        q.put(temp.get())
    
    return minimum