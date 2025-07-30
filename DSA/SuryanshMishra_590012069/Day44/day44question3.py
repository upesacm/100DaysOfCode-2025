# 3. Check if Queue is Empty
# A problem that teaches queue state validation techniques and demonstrates boolean condition checking for empty data structures using efficient state detection methods for control flow operations.

# Write a function to check whether the queue is empty or not and return a boolean result. This operation is fundamental in control flow logic and queue processing loops where you need to validate queue state before performing operations that require elements. The technique involves understanding state validation patterns that prevent errors in queue operations and enable safe processing workflows. This concept is essential in iterative processing, consumer-producer patterns, and queue-based algorithms where empty state detection prevents runtime errors and enables graceful handling of boundary conditions.

# This teaches state validation algorithms and boolean condition techniques that are essential for safe queue operations and efficient boundary condition handling.

# Your task: Implement reliable empty state detection that accurately identifies queue emptiness for safe operation control and error prevention.

# Examples
# Input:

# Queue = []
# Output:

# True
# Input:

# Queue = [1, 2]
# Output:

# False
from queue import Queue

def is_queue_empty(q: Queue) -> bool:
    return q.empty()
