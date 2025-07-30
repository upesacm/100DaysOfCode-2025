# 1. Sum of Elements in a Queue
# A problem that introduces queue aggregation techniques and teaches accumulative operations on queue data structures using traversal-based computation methods for statistical analysis.

# Calculate and return the sum of all elements present in a queue without modifying its structure. This operation is fundamental in statistical computation and data aggregation where you need to perform mathematical operations on queue contents while preserving the original data structure. The technique requires understanding accumulative traversal methods that process each queue element systematically. This concept is essential in financial calculations, data analytics, and mathematical processing where sum operations provide insights into data totals and enable further statistical computations on queue-based data streams.

# This teaches queue aggregation algorithms and accumulative computation techniques that are essential for statistical analysis and efficient mathematical operations on queue data structures.

# Your task: Implement queue traversal with accumulative summation to calculate total values while maintaining queue integrity and structure.

# Examples
# Input:

# [1, 2, 3]
# Output:

# 6
# Input:

# [10, 20, 30]
# Output:

# 60
from queue import Queue

def sum_queue_elements(q: Queue) -> int:
    total = 0
    size = q.qsize()
    
    for _ in range(size):
        element = q.get()
        total += element
        q.put(element)
    
    return total