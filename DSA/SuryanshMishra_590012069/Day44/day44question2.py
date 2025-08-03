# 2. Find the Size of a Queue
# A problem that demonstrates queue metadata operations and teaches efficient size calculation techniques for dynamic data structures using built-in properties or iterative counting methods.

# Given a queue, write a program to return the number of elements present in it. This operation is fundamental in memory management and capacity planning where you need to monitor queue utilization and track data structure growth. The technique involves understanding size tracking mechanisms that can be implemented through direct property access or iterative counting depending on the queue implementation. This concept is essential in resource allocation, performance monitoring, and system optimization where knowing data structure sizes enables efficient memory management and capacity planning decisions.

# This introduces queue metadata analysis and size tracking techniques that are crucial for resource management and efficient queue capacity monitoring operations.

# Your task: Implement efficient queue size calculation using appropriate methods based on the underlying queue implementation and access patterns.

# Examples
# Input:

# Queue = [1, 2, 3, 4]
# Output:

# 4
# Input:

# Queue = [7]
# Output:

# 1
from queue import Queue

def queue_size(q: Queue) -> int:
    return q.qsize()
