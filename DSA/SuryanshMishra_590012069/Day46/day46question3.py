# 3. Merge Two Queues
# A problem that teaches queue concatenation techniques and demonstrates linear data structure combination using sequential append operations for unified data structure creation and queue integration methods.

# Given two queues, merge them into a single unified queue by systematically appending all elements from the second queue to the first queue. This operation is fundamental in data integration and queue consolidation where you need to combine multiple data streams into unified structures for comprehensive processing. The technique requires understanding sequential append methods that preserve element ordering while efficiently transferring data between queue structures. This concept is essential in data pipeline processing, stream merging, and batch operations where queue combination enables unified data processing and facilitates comprehensive analysis on consolidated datasets.

# This teaches queue concatenation algorithms and sequential merging techniques that are essential for data integration and efficient queue combination operations.

# Your task: Implement systematic queue merging using sequential append operations to create unified data structures while maintaining element ordering and queue efficiency.

# Examples
# Input:

# Q1 = [1, 2], Q2 = [3, 4]
# Output:

# [1, 2, 3, 4]
# Input:

# Q1 = [5], Q2 = [6, 7]
# Output:

# [5, 6, 7]
from queue import Queue

def merge_queues(q1: Queue, q2: Queue) -> Queue:
    temp_q2 = Queue()
    
    while not q2.empty():
        item = q2.get()
        q1.put(item)
        temp_q2.put(item)

    while not temp_q2.empty():
        q2.put(temp_q2.get())

    return q1 

def print_queue(q: Queue):
    temp = Queue()
    while not q.empty():
        item = q.get()
        print(item, end=' ')
        temp.put(item)
    while not temp.empty():
        q.put(temp.get())
    print()