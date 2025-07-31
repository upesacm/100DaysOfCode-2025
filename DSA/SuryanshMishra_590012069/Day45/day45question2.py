# 2. Compare Two Queues
# A problem that demonstrates queue comparison algorithms and teaches element-by-element equality checking using systematic traversal methods for data structure validation and verification operations.

# Given two queues, check if they are identical in order and content through systematic comparison. This operation is fundamental in data validation and queue synchronization where you need to verify data consistency between different queue instances. The technique involves understanding parallel traversal methods that compare corresponding elements while maintaining queue structures. This concept is essential in testing frameworks, data replication, and quality assurance where queue equality verification ensures data integrity and system correctness across distributed or replicated queue systems.

# This introduces queue comparison algorithms and parallel traversal techniques that are crucial for data validation and efficient queue equality verification operations.

# Your task: Implement systematic queue comparison using parallel element traversal to verify complete structural and content equality between queue instances.

# Examples
# Input:

# Q1 = [1, 2, 3], Q2 = [1, 2, 3]
# Output:

# Yes
# Input:

# Q1 = [1, 2], Q2 = [2, 1]
# Output:

# No
from queue import Queue

def are_queues_equal(q1: Queue, q2: Queue) -> str:
    if q1.qsize() != q2.qsize():
        return "No"
    
    size = q1.qsize()
    equal = True

    for _ in range(size):
        elem1 = q1.get()
        elem2 = q2.get()

        if elem1 != elem2:
            equal = False

        q1.put(elem1)
        q2.put(elem2)

    return "Yes" if equal else "No"